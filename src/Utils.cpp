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

            TR_GLENUM_TO_STRING(GL_DEBUG_SOURCE_API);
            TR_GLENUM_TO_STRING(GL_DEBUG_SOURCE_WINDOW_SYSTEM);
            TR_GLENUM_TO_STRING(GL_DEBUG_SOURCE_SHADER_COMPILER);
            TR_GLENUM_TO_STRING(GL_DEBUG_SOURCE_THIRD_PARTY);
            TR_GLENUM_TO_STRING(GL_DEBUG_SOURCE_APPLICATION);
            TR_GLENUM_TO_STRING(GL_DEBUG_SOURCE_OTHER);

            TR_GLENUM_TO_STRING(GL_DEBUG_TYPE_ERROR);
            TR_GLENUM_TO_STRING(GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR);
            TR_GLENUM_TO_STRING(GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR);
            TR_GLENUM_TO_STRING(GL_DEBUG_TYPE_PORTABILITY);
            TR_GLENUM_TO_STRING(GL_DEBUG_TYPE_PERFORMANCE);
            TR_GLENUM_TO_STRING(GL_DEBUG_TYPE_OTHER);
            TR_GLENUM_TO_STRING(GL_DEBUG_TYPE_MARKER);
            TR_GLENUM_TO_STRING(GL_DEBUG_TYPE_PUSH_GROUP);
            TR_GLENUM_TO_STRING(GL_DEBUG_TYPE_POP_GROUP);

            TR_GLENUM_TO_STRING(GL_DEBUG_SEVERITY_NOTIFICATION);
            TR_GLENUM_TO_STRING(GL_DEBUG_SEVERITY_HIGH);
            TR_GLENUM_TO_STRING(GL_DEBUG_SEVERITY_MEDIUM);
            TR_GLENUM_TO_STRING(GL_DEBUG_SEVERITY_LOW);

        default:
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Invalid enumeration value: ",
                    e));
        }
    }

    std::runtime_error forward_exception(
        const std::string &debug_info,
        const std::exception &exception)
    {
        return std::runtime_error(
            to_string(
                debug_info,
                exception.what()));
    }

    std::string get_text_from_stream(std::istream &is)
    {
        std::stringstream sstr;
        std::string temp;
        while (getline(is, temp))
            sstr << temp << std::endl;
        return sstr.str();
    }

    std::vector<Char> get_bytes_from_stream(std::istream &is)
    {
        std::vector<Char> bytes;
        char byte;
        while (is.read(&byte, sizeof(Char)))
            bytes.push_back(byte);
        return bytes;
    }

    std::ifstream open_file(const std::string &filename)
    {
        std::ifstream fin;
        fin.open(filename);

        if (fin.fail())
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Unable to open file: \"",
                    filename,
                    "\""));

        return fin;
    }

    std::string get_text_from_file(const std::string &filename)
    {
        std::ifstream fin = open_file(filename);
        std::string result = get_text_from_stream(fin);
        fin.close();
        return result;
    }

    std::vector<Char> get_bytes_from_file(const std::string &filename)
    {
        std::ifstream fin = open_file(filename);
        std::vector<Char> result = get_bytes_from_stream(fin);
        fin.close();
        return result;
    }

} // namespace tr

#endif
