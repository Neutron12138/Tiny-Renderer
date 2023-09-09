#ifndef TR_PROGRAM_CPP
#define TR_PROGRAM_CPP

#include "Program.hpp"

namespace tr
{
    Program::Program() : Resource<GLuint>()
    {
        data() = glCreateProgram();
    }

    Program::Program(GLuint id) : Resource<GLuint>(id)
    {
        check_id(id);
    }

    Program::~Program()
    {
        if (!is_null())
            glDeleteProgram(data());
        data() = 0;
    }

    GLuint Program::get_id() const
    {
        return data();
    }

    bool Program::is_null() const
    {
        return data() == 0;
    }

    void Program::attach_shaders(const std::vector<ShaderRes> &shaders)
    {
        m_attached_shaders = shaders;
        for (auto iter = shaders.cbegin(); iter != shaders.cend(); iter++)
            glAttachShader(data(), iter->operator*().get_id());
        glLinkProgram(data());
        check_error(data());
    }

    void Program::load_from_string(const std::string &vsource, const std::string &fsource)
    {
    }

    void Program::load_from_string(const std::string &vsource, const std::string &fsource, const std::string &gsource)
    {
    }

    void Program::check_id(GLuint id)
    {
        if (id == 0)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Program ID is a reserved value (is 0)"));

        if (glIsProgram(id))
            return;
        throw std::runtime_error(
            to_string(
                TR_DEBUG,
                "The ID (value: ",
                id,
                ") is not a program"));
    }

    void Program::check_error(GLuint id)
    {
        GLint length;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
        if (length <= 0)
            return;

        std::vector<char> info_log(length);
        glGetProgramInfoLog(id, length, nullptr, info_log.data());
        throw std::runtime_error(
            to_string(
                TR_DEBUG,
                info_log.data()));
    }

} // namespace tr

#endif
