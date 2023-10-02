#ifndef TR_VERTEXBUFFER_HPP
#define TR_VERTEXBUFFER_HPP

#include "Buffer.hpp"

namespace tr
{
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
