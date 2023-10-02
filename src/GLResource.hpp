#ifndef TR_GLRESOURCE_HPP
#define TR_GLRESOURCE_HPP

#include <GL/glew.h>
#include "Resource.hpp"
#include "Utils.hpp"

namespace tr
{
    //
    // GLResource
    //

    class GLResource : public Resource
    {
    public:
        using ParentType = Resource;

    private:
        GLuint m_data;

    public:
        GLResource(GLuint id = 0);

    protected:
        GLuint &data();
        const GLuint &data() const;

    public:
        GLuint get_id() const;
        bool is_null() const;

    public:
        virtual void delete_self() = 0;
        virtual void generate_id() = 0;

    public:
        static void check_id(GLuint id);
    };

    //
    // Bindable
    //

    class Bindable : public GLResource
    {
    public:
        using ParentType = GLResource;

    public:
        Bindable(GLuint id = 0);

    public:
        virtual void bind() = 0;
        virtual void unbind() = 0;
    };

} // namespace tr

#endif
