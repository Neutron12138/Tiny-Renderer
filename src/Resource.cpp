#ifndef TR_RESOURCE_CPP
#define TR_RESOURCE_CPP

#include "Resource.hpp"

namespace tr
{
    template <typename T>
    Resource<T>::Resource(const T &data)
        : m_data(data) {}

    template <typename T>
    T &Resource<T>::data()
    {
        return SelfType::m_data;
    }

    template <typename T>
    const T &Resource<T>::data() const
    {
        return SelfType::m_data;
    }

} // namespace tr

#endif
