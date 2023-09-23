#ifndef TR_UTILS_HPP
#define TR_UTILS_HPP

#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <fstream>
#include <GL/glew.h>
#include "BasicType.hpp"

#define TR_DEBUG                        \
    tr::to_string(                      \
        "[at file: \"", __FILE__,       \
        "\", line: ", __LINE__,         \
        ", function: \"", __FUNCTION__, \
        "\"]\n")

#define TR_TRY(statement)                                                   \
    try                                                                     \
    {                                                                       \
        statement;                                                          \
    }                                                                       \
    catch (const std::exception &e)                                         \
    {                                                                       \
        std::cout << e.what() << std::endl;                                 \
    }                                                                       \
    catch (const char *e)                                                   \
    {                                                                       \
        std::cout << e << std::endl;                                        \
    }                                                                       \
    catch (const std::string &e)                                            \
    {                                                                       \
        std::cout << e << std::endl;                                        \
    }                                                                       \
    catch (...)                                                             \
    {                                                                       \
        std::cout << "The program threw an unknown exception" << std::endl; \
    }

#define TR_TRYS(statements)                                                 \
    try                                                                     \
    {                                                                       \
        statements                                                          \
    }                                                                       \
    catch (const std::exception &e)                                         \
    {                                                                       \
        std::cout << e.what() << std::endl;                                 \
    }                                                                       \
    catch (const char *e)                                                   \
    {                                                                       \
        std::cout << e << std::endl;                                        \
    }                                                                       \
    catch (const std::string &e)                                            \
    {                                                                       \
        std::cout << e << std::endl;                                        \
    }                                                                       \
    catch (...)                                                             \
    {                                                                       \
        std::cout << "The program threw an unknown exception" << std::endl; \
    }

namespace tr
{
    std::string to_string();
    float get_current_clocks();
    std::string glenum_to_string(GLenum e);

    std::runtime_error forward_exception(const std::string &debug_info, const std::exception &exception);

    std::string get_text_from_stream(std::istream &is);
    std::vector<Char> get_bytes_from_stream(std::istream &is);

    std::ifstream open_file(const std::string &filename);
    std::string get_text_from_file(const std::string &filename);
    std::vector<Char> get_bytes_from_file(const std::string &filename);

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
