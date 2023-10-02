#ifndef TR_PROGRAM_CPP
#define TR_PROGRAM_CPP

#include "Program.hpp"

namespace tr
{
    Program::Program() : GLResource() {}

    Program::Program(GLuint id) : GLResource(id)
    {
        check_id(id);
    }

    Program::~Program()
    {
        delete_self();
    }

    const Program::ShaderContainer &Program::get_attached_shaders() const
    {
        return m_attached_shaders;
    }

    void Program::attach_shaders(const ShaderContainer &shaders)
    {
        if (shaders.size() == 0)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "The list of shaders to be attached is empty and cannot be attached to the program"));

        delete_self();
        generate_id();
        m_attached_shaders = shaders;

        for (auto iter = shaders.cbegin(); iter != shaders.cend(); iter++)
            glAttachShader(data(), iter->operator*().get_id());
        glLinkProgram(data());
        check_error(data());
    }

    void Program::compile_from_string(const std::string &vsource, const std::string &fsource)
    {
        tr::ShaderRes vshader = make_res<Shader>();
        vshader->compile_from_string(vsource, Shader::VERTEX);

        tr::ShaderRes fshader = make_res<Shader>();
        fshader->compile_from_string(fsource, Shader::FRAGMENT);

        attach_shaders({vshader, fshader});
    }

    void Program::compile_from_string(const std::string &vsource, const std::string &fsource, const std::string &gsource)
    {
        tr::ShaderRes vshader = make_res<Shader>();
        vshader->compile_from_string(vsource, Shader::VERTEX);

        tr::ShaderRes fshader = make_res<Shader>();
        fshader->compile_from_string(fsource, Shader::FRAGMENT);

        tr::ShaderRes gshader = make_res<Shader>();
        gshader->compile_from_string(gsource, Shader::GEOMETRY);

        attach_shaders({vshader, fshader, gshader});
    }

    void Program::compile_from_stream(std::istream &vis, std::istream &fis)
    {
        std::string vsource = get_text_from_stream(vis);
        std::string fsource = get_text_from_stream(fis);
        compile_from_string(vsource, fsource);
    }

    void Program::compile_from_stream(std::istream &vis, std::istream &fis, std::istream &gis)
    {
        std::string vsource = get_text_from_stream(vis);
        std::string fsource = get_text_from_stream(fis);
        std::string gsource = get_text_from_stream(gis);
        compile_from_string(vsource, fsource, gsource);
    }

    void Program::compile_from_file(const std::string &vfilename, const std::string &ffilename)
    {
        std::string vsource = get_text_from_file(vfilename);
        std::string fsource = get_text_from_file(ffilename);
        compile_from_string(vsource, fsource);
    }

    void Program::compile_from_file(const std::string &vfilename, const std::string &ffilename, const std::string &gfilename)
    {
        std::string vsource = get_text_from_file(vfilename);
        std::string fsource = get_text_from_file(ffilename);
        std::string gsource = get_text_from_file(gfilename);
        compile_from_string(vsource, fsource, gsource);
    }

    GLint Program::get_parameter(GLenum pname) const
    {
        return get_program_param(data(), pname);
    }

    GLint Program::get_uniform_location(const std::string &name) const
    {
        GLint location = glGetUniformLocation(data(), name.data());

        if (location == -1)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Unable to find uniform: \"",
                    name,
                    "\""));

        return location;
    }

    GLint Program::get_attrib_location(const std::string &name) const
    {
        GLint location = glGetAttribLocation(data(), name.data());

        if (location == -1)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Unable to find attrib: \"",
                    name,
                    "\""));

        return location;
    }

    void Program::use_program() const
    {
        if (data() != 0)
            glUseProgram(data());
    }

    void Program::delete_self()
    {
        if (!is_null())
            glDeleteProgram(data());
        data() = 0;
    }

    void Program::generate_id()
    {
        delete_self();
        data() = glCreateProgram();
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
        GLint success = get_program_param(id, GL_LINK_STATUS);
        if (success)
            return;

        GLint length = get_program_param(id, GL_INFO_LOG_LENGTH);
        std::vector<char> info_log(length);

        glGetProgramInfoLog(id, length, nullptr, info_log.data());
        throw std::runtime_error(
            to_string(
                TR_DEBUG,
                info_log.data()));
    }

    GLint Program::get_program_param(GLuint id, GLenum pname)
    {
        if (id == 0)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Program ID is a reserved value (is 0)"));

        if (pname != GL_DELETE_STATUS)
            if (get_program_param(id, GL_DELETE_STATUS))
                throw std::runtime_error(
                    to_string(
                        TR_DEBUG,
                        "The program (ID: ",
                        id,
                        ") has been deleted"));

        GLint result = 0;
        glGetProgramiv(id, pname, &result);
        return result;
    }

} // namespace tr

#endif
