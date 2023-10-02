#ifndef TR_SHADER_CPP
#define TR_SHADER_CPP

#include "Shader.hpp"

namespace tr
{
    Shader::Shader(Type type)
        : ParentType(), m_type(type)
    {
        check_type(type);
    }

    Shader::Shader(Type type, GLuint id)
        : ParentType(id), m_type(type)
    {
        check_type(type);
        check_id(id);
    }

    Shader::~Shader()
    {
        delete_self();
    }

    Shader::Type Shader::get_type() const
    {
        return m_type;
    }

    void Shader::compile_from_string(const std::string &source)
    {
        if (source.size() == 0)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Unable to compile empty string as a shader"));

        delete_self();
        generate_id();

        const char *ptr = source.data();
        glShaderSource(data(), 1, &ptr, nullptr);
        glCompileShader(data());
        check_error(data());
    }

    void Shader::compile_from_string(const std::string &source, Type new_type)
    {
        m_type = new_type;
        compile_from_string(source);
    }

    void Shader::compile_from_stream(std::istream &is)
    {
        std::string source = get_text_from_stream(is);
        compile_from_string(source);
    }

    void Shader::compile_from_stream(std::istream &is, Type new_type)
    {
        std::string source = get_text_from_stream(is);
        compile_from_string(source, new_type);
    }

    void Shader::compile_from_file(const std::string &filename)
    {
        std::string source = get_text_from_file(filename);
        compile_from_string(source);
    }

    void Shader::compile_from_file(const std::string &filename, Type new_type)
    {
        std::string source = get_text_from_file(filename);
        compile_from_string(source);
    }

    GLint Shader::get_parameter(GLenum pname) const
    {
        return get_shader_param(data(), pname);
    }

    void Shader::delete_self()
    {
        if (!is_null())
            glDeleteShader(data());
        data() = 0;
    }

    void Shader::generate_id()
    {
        delete_self();
        check_type(m_type);
        data() = glCreateShader(m_type);
    }

    void Shader::check_type(std::uint32_t type)
    {
        if (!(type == GL_VERTEX_SHADER ||
              type == GL_FRAGMENT_SHADER ||
              type == GL_GEOMETRY_SHADER ||
              type == GL_COMPUTE_SHADER))
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Shader type error, value: ",
                    type));
    }

    void Shader::check_id(GLuint id)
    {
        if (id == 0)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Shader ID is a reserved value (is 0)"));

        if (glIsShader(id))
            return;
        throw std::runtime_error(
            to_string(
                TR_DEBUG,
                "The ID (value: ",
                id,
                ") is not a shader"));
    }

    void Shader::check_error(GLuint id)
    {
        GLint success = get_shader_param(id, GL_COMPILE_STATUS);
        if (success)
            return;

        GLint length = get_shader_param(id, GL_INFO_LOG_LENGTH);
        std::vector<char> info_log(length);

        glGetShaderInfoLog(id, length, nullptr, info_log.data());
        throw std::runtime_error(
            to_string(
                TR_DEBUG,
                info_log.data()));
    }

    GLint Shader::get_shader_param(GLuint id, GLenum pname)
    {
        if (id == 0)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Shader ID is a reserved value (is 0)"));

        if (pname != GL_DELETE_STATUS)
            if (get_shader_param(id, GL_DELETE_STATUS))
                throw std::runtime_error(
                    to_string(
                        TR_DEBUG,
                        "The shader (ID: ",
                        id,
                        ") has been deleted"));

        GLint result = 0;
        glGetShaderiv(id, pname, &result);
        return result;
    }

} // namespace tr

#endif
