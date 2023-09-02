#ifndef TR_SHADER_CPP
#define TR_SHADER_CPP

#include "Shader.hpp"

namespace tr
{
    Shader::Shader(GLenum type)
        : ParentType(), m_type(type)
    {
        check_type(type);
        data() = glCreateShader(type);
    }

    Shader::Shader(GLenum type, GLuint id)
        : ParentType(id), m_type(type)
    {
        check_type(type);
        check_id(id);
    }

    Shader::~Shader()
    {
        if (!is_null())
            glDeleteShader(data());
        data() = 0;
    }

    void Shader::load_from_string(const std::string &source)
    {
        check_id(data());

        const char *ptr = source.data();
        glShaderSource(data(), 1, &ptr, nullptr);
        glCompileShader(data());
        check_error(data());
    }

    void Shader::check_type(GLenum type)
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
        GLint length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        if (length <= 0)
            return;

        std::vector<char> info_log(length);
        glGetShaderInfoLog(id, length, nullptr, info_log.data());
        throw std::runtime_error(
            to_string(
                TR_DEBUG,
                info_log.data()));
    }

} // namespace tr

#endif
