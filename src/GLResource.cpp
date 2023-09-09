#ifndef TR_GLRESOURCE_CPP
#define TR_GLRESOURCE_CPP

#include "GLResource.hpp"

namespace tr
{
    GLResource::GLResource()
        : Resource<GLuint>() {}

    GLResource::GLResource(GLuint id) : Resource<GLuint>(id)
    {
        check_id(id);
    }

    GLuint GLResource::get_id() const
    {
        return data();
    }

    bool GLResource::is_null() const
    {
        return data() == 0;
    }

    void GLResource::check_id(GLuint id)
    {
        if (id == 0)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "OpenGL Object ID is a reserved value (is 0)"));
    }

} // namespace tr

#endif
