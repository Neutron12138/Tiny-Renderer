#ifndef TR_SHADER_HPP
#define TR_SHADER_HPP

#include <string>
#include <vector>
#include <memory>
#include <GL/glew.h>
#include "GLResource.hpp"

namespace tr
{
    class Shader : public GLResource
    {
    public:
        using ParentType = GLResource;

    private:
        GLenum m_type = GL_NONE;

    public:
        Shader(GLenum type);
        Shader(GLenum type, GLuint id);
        ~Shader();

    public:
        void load_from_string(const std::string &source);

    public:
        static void check_type(GLenum type);
        static void check_id(GLuint id);
        static void check_error(GLuint id);
    };

    using ShaderRes = std::shared_ptr<Shader>;

} // namespace tr

#endif
