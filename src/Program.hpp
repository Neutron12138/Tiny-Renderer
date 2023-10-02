#ifndef TR_PROGRAM_HPP
#define TR_PROGRAM_HPP

#include "Shader.hpp"

namespace tr
{
    class Program : public GLResource
    {
    public:
        using ShaderContainer = std::vector<ShaderRes>;
        using ParentType = GLResource;

    private:
        ShaderContainer m_attached_shaders;

    public:
        Program();
        Program(GLuint id);
        ~Program();

    public:
        const ShaderContainer &get_attached_shaders() const;

    public:
        void attach_shaders(const ShaderContainer &shaders);
        void compile_from_string(const std::string &vsource, const std::string &fsource);
        void compile_from_string(const std::string &vsource, const std::string &fsource, const std::string &gsource);
        void compile_from_stream(std::istream &vis, std::istream &fis);
        void compile_from_stream(std::istream &vis, std::istream &fis, std::istream &gis);
        void compile_from_file(const std::string &vfilename, const std::string &ffilename);
        void compile_from_file(const std::string &vfilename, const std::string &ffilename, const std::string &gfilename);

    public:
        GLint get_parameter(GLenum pname) const;
        GLint get_uniform_location(const std::string &name) const;
        GLint get_attrib_location(const std::string &name) const;

    public:
        void use_program() const;

    public:
        void delete_self() override;
        void generate_id() override;

    public:
        static void check_id(GLuint id);
        static void check_error(GLuint id);
        static GLint get_program_param(GLuint id, GLenum pname);
    };

    using ProgramRes = Res<Program>;

} // namespace tr

#endif
