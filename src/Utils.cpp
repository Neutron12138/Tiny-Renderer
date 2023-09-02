#ifndef TR_UTILS_CPP
#define TR_UTILS_CPP

#include "Utils.hpp"

#define TR_GLENUM_TO_STRING(e) \
    case e:                    \
        return #e

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

    std::string glenum_to_string(GLenum e)
    {
        switch (e)
        {
            TR_GLENUM_TO_STRING(GL_VERTEX_SHADER);
            TR_GLENUM_TO_STRING(GL_FRAGMENT_SHADER);
            TR_GLENUM_TO_STRING(GL_GEOMETRY_SHADER);
            TR_GLENUM_TO_STRING(GL_COMPUTE_SHADER);

        default:
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Invalid enumeration value: ",
                    e));
        }
    }

} // namespace tr

#endif
