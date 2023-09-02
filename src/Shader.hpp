#ifndef TR_SHADER_HPP
#define TR_SHADER_HPP

#include <string>
#include <vector>
#include <GL/glew.h>
#include "Resource.hpp"
#include "Utils.hpp"

namespace tr
{
    class Shader : public Resource<GLuint>
    {
    public:
        using ParentType = Resource<GLuint>;

    private:
        GLenum m_type = GL_NONE;

    public:
        Shader(GLenum type);
        Shader(GLenum type, GLuint id);
        ~Shader();

    public:
        GLuint get_id() const;
        bool is_null() const;

    public:
        void load_from_string(const std::string &source);

    public:
        static void check_type(GLenum type);
        static void check_id(GLuint id);
        static void check_error(GLuint id);
    };

} // namespace tr

#endif
