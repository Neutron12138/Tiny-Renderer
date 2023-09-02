#ifndef TR_GLRESOURCE_HPP
#define TR_GLRESOURCE_HPP

#include <GL/glew.h>
#include "Resource.hpp"
#include "Utils.hpp"

namespace tr
{
    class GLResource : public Resource<GLuint>
    {
    public:
        using ParentType = Resource<GLuint>;

    public:
        GLResource();
        GLResource(GLuint id);

    public:
        GLuint get_id() const;
        bool is_null() const;

    public:
        static void check_id(GLuint id);
    };

} // namespace tr

#endif
