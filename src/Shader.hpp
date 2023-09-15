#ifndef TR_SHADER_HPP
#define TR_SHADER_HPP

#include <string>
#include <vector>
#include <GL/glew.h>
#include "GLResource.hpp"
#include "ResourceHolder.hpp"
#include "BasicType.hpp"

namespace tr
{
    class Shader : public GLResource
    {
    public:
        enum Type : UInt32
        {
            NONE = 0,
            VERTEX = GL_VERTEX_SHADER,
            FRAGMENT = GL_FRAGMENT_SHADER,
            GEOMETRY = GL_GEOMETRY_SHADER,
            COMPUTE = GL_COMPUTE_SHADER,
            COUNT = 4,
        };

        using ParentType = GLResource;

    private:
        Type m_type = NONE;

    public:
        Shader(Type type = NONE);
        Shader(Type type, GLuint id);
        ~Shader();

    public:
        Type get_type() const;

    public:
        void compile_from_string(const std::string &source);
        void compile_from_string(const std::string &source, Type new_type);
        void compile_from_stream(std::istream &is);
        void compile_from_stream(std::istream &is, Type new_type);
        void compile_from_file(const std::string &filename);
        void compile_from_file(const std::string &filename, Type new_type);

    public:
        GLint get_parameter(GLenum pname) const;

    public:
        void delete_self() override;
        void generate_id() override;

    public:
        static void check_type(UInt32 type);
        static void check_id(GLuint id);
        static void check_error(GLuint id);
        static GLint get_shader_param(GLuint id, GLenum pname);
    };

    using ShaderRes = Res<Shader>;

} // namespace tr

#endif
