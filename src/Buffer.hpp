#ifndef TR_BUFFER_HPP
#define TR_BUFFER_HPP

#include "GLResource.hpp"
#include "ResourceHolder.hpp"

namespace tr
{
    //
    // Buffer
    //

    class Buffer : public Bindable
    {
    public:
        enum Type : UInt32
        {
            NONE = 0,
            ARRAY_BUFFER = GL_ARRAY_BUFFER,
            ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER,
            COUNT = 2,
        };

        using ParentType = Bindable;

    private:
        Type m_type = NONE;

    public:
        Buffer(Type type = NONE);
        Buffer(Type type, GLuint id);
        ~Buffer();

    public:
        void set_data(GLsizeiptr size, const void *data, GLenum usage = GL_STATIC_DRAW);
        template <typename T>
        void set_data(const T *data, std::size_t size, GLenum usage = GL_STATIC_DRAW);
        template <typename T>
        void set_data(const std::vector<T> &data, GLenum usage = GL_STATIC_DRAW);

        void sub_data(GLintptr offset, GLsizeiptr size, const void *data);
        template <typename T>
        void sub_data(std::size_t index, const T *data, std::size_t size);
        template <typename T>
        void sub_data(std::size_t index, const std::vector<T> &data);

    public:
        Type get_type() const;

    public:
        void bind() override;
        void unbind() override;
        void delete_self() override;
        void generate_id() override;

    public:
        static void check_type(UInt32 type);
        static void check_id(GLuint id);
    };

    using BufferRes = Res<Buffer>;

    //
    // VertexBuffer
    //

    class VertexBuffer : public Buffer
    {
    public:
        VertexBuffer(GLuint id = 0);

    public:
        void enable_vertex_attrib_array(GLuint index);
        void vertex_attrib_pointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
        void vertex_attrib_pointer(GLuint index, GLint size, std::size_t stride, std::size_t offset);

    public:
        void bind() override;
        void unbind() override;

    public:
        static void check_type(UInt32 type);
    };

    using VertexBufferRes = Res<VertexBuffer>;

} // namespace tr

#endif
