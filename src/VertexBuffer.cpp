#ifndef TR_VERTEXBUFFER_CPP
#define TR_VERTEXBUFFER_CPP

#include "VertexBuffer.hpp"

namespace tr
{
    VertexBuffer::VertexBuffer(GLuint id)
        : Buffer(ARRAY_BUFFER, id) {}

    void VertexBuffer::enable_vertex_attrib_array(GLuint index)
    {
        glEnableVertexAttribArray(index);
    }

    void VertexBuffer::vertex_attrib_pointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
    {
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    }

    void VertexBuffer::vertex_attrib_pointer(GLuint index, GLint size, std::size_t stride, std::size_t offset)
    {
        vertex_attrib_pointer(index, size, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<const void *>(offset));
    }

    void VertexBuffer::bind()
    {
        glBindBuffer(ARRAY_BUFFER, data());
    }

    void VertexBuffer::unbind()
    {
        glBindBuffer(ARRAY_BUFFER, 0);
    }

    void VertexBuffer::check_type(UInt32 type)
    {
        if (type != ARRAY_BUFFER)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Vertex Buffer type error, value: ",
                    type));
    }

} // namespace tr

#endif
