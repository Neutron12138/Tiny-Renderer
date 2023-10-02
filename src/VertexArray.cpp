#ifndef TR_VERTEXARRAY_CPP
#define TR_VERTEXARRAY_CPP

#include "VertexArray.hpp"

namespace tr
{
    VertexArray::VertexArray(GLuint id)
        : Bindable(id) {}

    VertexArray::~VertexArray()
    {
        delete_self();
    }

    const VertexArray::BufferContainer &VertexArray::get_buffers() const
    {
        return m_buffers;
    }

    void VertexArray::bind_buffer(const BufferRes &buffer)
    {
        m_buffers.push_back(buffer);
        buffer->bind();
    }

    void VertexArray::bind_buffers(const BufferContainer &buffers)
    {
        m_buffers = buffers;
        for (auto iter = buffers.begin(); iter != buffers.end(); iter++)
            (*iter)->bind();
    }

    void VertexArray::bind()
    {
        glBindVertexArray(data());
    }

    void VertexArray::unbind()
    {
        glBindVertexArray(0);
    }

    void VertexArray::delete_self()
    {
        if (data() != 0)
            glDeleteVertexArrays(1, &data());
        data() = 0;
    }

    void VertexArray::generate_id()
    {
        delete_self();
        glGenVertexArrays(1, &data());
    }

    void VertexArray::check_id(GLuint id)
    {
        if (id == 0)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "VertexArray ID is a reserved value (is 0)"));

        if (glIsVertexArray(id))
            return;
        throw std::runtime_error(
            to_string(
                TR_DEBUG,
                "The ID (value: ",
                id,
                ") is not a vertex array"));
    }

} // namespace tr

#endif
