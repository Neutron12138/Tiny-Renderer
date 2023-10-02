#ifndef TR_RESOURCEHOLDER_HPP
#define TR_RESOURCEHOLDER_HPP

#include <memory>
#include "Utils.hpp"

#define TR_RESOURCEHOLDER_NULLPTR \
    std::runtime_error(           \
        tr::to_string(            \
            TR_DEBUG,             \
            "Attempting to access a null pointer"))

#define TR_RESOURCEHOLDER_ASSIGN(PREFIX, TYPE) \
    PREFIX                                     \
    ResourceHolder(TYPE ptr)                   \
        : ParentType(ptr) {}                   \
    PREFIX                                     \
    SelfType &                                 \
    operator=(TYPE ptr)                        \
    {                                          \
        ParentType::operator=(ptr);            \
        return *this;                          \
    }

namespace tr
{
    template <typename T>
    class ResourceHolder : public std::shared_ptr<T>
    {
    public:
        using DataType = T;
        using SelfType = ResourceHolder<DataType>;
        using ParentType = std::shared_ptr<T>;

    public:
        ResourceHolder() : ParentType() {}
        TR_RESOURCEHOLDER_ASSIGN(, std::nullptr_t)
        TR_RESOURCEHOLDER_ASSIGN(template <typename Y>, Y *)
        TR_RESOURCEHOLDER_ASSIGN(template <typename Y>, const std::shared_ptr<Y> &)
        TR_RESOURCEHOLDER_ASSIGN(template <typename Y>, const ResourceHolder<Y> &)
        TR_RESOURCEHOLDER_ASSIGN(, const SelfType &)

    public:
        DataType &operator*()
        {
            if (ParentType::get() == nullptr)
                throw TR_RESOURCEHOLDER_NULLPTR;

            return ParentType::operator*();
        }

        DataType &operator*() const
        {
            if (ParentType::get() == nullptr)
                throw TR_RESOURCEHOLDER_NULLPTR;

            return ParentType::operator*();
        }

        DataType *operator->()
        {
            if (ParentType::get() == nullptr)
                throw TR_RESOURCEHOLDER_NULLPTR;

            return ParentType::get();
        }

        DataType *operator->() const
        {
            if (ParentType::get() == nullptr)
                throw TR_RESOURCEHOLDER_NULLPTR;

            return ParentType::get();
        }

    public:
        template <typename... ArgsT>
        SelfType &create(ArgsT &&...args)
        {
            ParentType::operator=(
                std::make_shared<DataType>(
                    std::forward<ArgsT>(args)...));

            return *this;
        }

        bool is_nullptr() const
        {
            return ParentType::get() == nullptr;
        }
    };

    template <typename T>
    using Res = ResourceHolder<T>;

    template <typename T, typename... ArgsT>
    Res<T> make_res(ArgsT &&...args)
    {
        Res<T> result;
        result.create(std::forward<ArgsT>(args)...);
        return result;
    }

} // namespace tr

#endif
