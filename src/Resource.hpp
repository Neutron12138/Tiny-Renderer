#ifndef TR_RESOURCE_HPP
#define TR_RESOURCE_HPP

#include <functional>
#include "Object.hpp"

namespace tr
{
    template <typename T>
    class Resource : public NonCopyable
    {
    public:
        using DataType = T;
        using SelfType = Resource<DataType>;

    private:
        DataType m_data;

    public:
        Resource(const DataType &data = T())
            : NonCopyable(), m_data(data) {}

    protected:
        DataType &data()
        {
            return m_data;
        }

        const DataType &data() const
        {
            return m_data;
        }
    };

} // namespace tr

#endif
