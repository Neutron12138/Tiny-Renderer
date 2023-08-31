#ifndef TR_UTILS_CPP
#define TR_UTILS_CPP

#include "Utils.hpp"

namespace tr
{
    std::string to_string()
    {
        return {};
    }

    template <typename T>
    std::string to_string(const T &value)
    {
        std::stringstream sstr;
        sstr << value;
        return sstr.str();
    }

    template <typename T, typename... ArgsT>
    std::string to_string(const T &value, const ArgsT &...args)
    {
        return to_string(value) + to_string(args...);
    }

    template <>
    std::string to_string(const std::string &value)
    {
        return value;
    }

    float get_current_clocks()
    {
        const float CPS = static_cast<float>(CLOCKS_PER_SEC);

        std::clock_t curr = std::clock();
        float currf = static_cast<float>(curr);
        float result = currf / CPS;

        return result;
    }

} // namespace tr

#endif
