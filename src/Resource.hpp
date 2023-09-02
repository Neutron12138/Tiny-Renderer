#ifndef TR_RESOURCE_HPP
#define TR_RESOURCE_HPP

#include <functional>

namespace tr
{
    template <typename T>
    class Resource
    {
    public:
        using SelfType = Resource<T>;

    private:
        T m_data;

    public:
        Resource(const T &data = T());

    protected:
        T &data();
        const T &data() const;
    };

} // namespace tr

#endif
