#ifndef TR_GLRESOURCE_CPP
#define TR_GLRESOURCE_CPP

#include "GLResource.hpp"

namespace tr
{
    //
    // GLResource
    //

    GLResource::GLResource(GLuint id)
        : Resource(), m_data(id) {}

    GLuint &GLResource::data()
    {
        return m_data;
    }

    const GLuint &GLResource::data() const
    {
        return m_data;
    }

    GLuint GLResource::get_id() const
    {
        return m_data;
    }

    bool GLResource::is_null() const
    {
        return m_data == 0;
    }

    void GLResource::check_id(GLuint id)
    {
        if (id == 0)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "OpenGL Object ID is a reserved value (is 0)"));
    }

    //
    // Bindable
    //

    Bindable::Bindable(GLuint id)
        : GLResource(id) {}

} // namespace tr

#endif
