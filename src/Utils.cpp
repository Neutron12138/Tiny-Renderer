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
    std::string to_string(const T &value, ArgsT &&...args)
    {
        return to_string(value) + to_string(std::forward<ArgsT>(args)...);
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

            TR_GLENUM_TO_STRING(GL_INVALID_ENUM);
            TR_GLENUM_TO_STRING(GL_INVALID_VALUE);
            TR_GLENUM_TO_STRING(GL_INVALID_OPERATION);
            TR_GLENUM_TO_STRING(GL_STACK_OVERFLOW);
            TR_GLENUM_TO_STRING(GL_STACK_UNDERFLOW);
            TR_GLENUM_TO_STRING(GL_OUT_OF_MEMORY);

        default:
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Invalid enumeration value: ",
                    e));
        }
    }

    template <typename RetT, typename... ArgsT>
    RetT run_gl_function(RetT (*func)(ArgsT...), ArgsT &&...args)
    {
        if (func == nullptr)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Function cannot be a null pointer"));

        RetT result = func(std::forward<ArgsT>(args)...);
        GLenum error = glGetError();

        if (error != GL_NO_ERROR)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "An error occurred while executing the OpenGL function, error: \"",
                    glenum_to_string(error),
                    "\""));

        return result;
    }

} // namespace tr

#endif
