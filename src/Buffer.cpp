#ifndef TR_BUFFER_CPP
#define TR_BUFFER_CPP

#include "Buffer.hpp"

namespace tr
{
    Buffer::Buffer(Type type)
        : Bindable(), m_type(type)
    {
        check_type(type);
    }

    Buffer::Buffer(Type type, GLuint id)
        : Bindable(id), m_type(type)
    {
        check_type(type);
        check_id(id);
    }

    Buffer::~Buffer()
    {
        delete_self();
    }

    void Buffer::set_data(GLsizeiptr size, const void *data, GLenum usage)
    {
        glBufferData(m_type, size, data, usage);
    }

    template <typename T>
    void Buffer::set_data(const T *data, std::size_t size, GLenum usage)
    {
        set_data(size * sizeof(T), reinterpret_cast<const void *>(data), usage);
    }

    template <typename T>
    void Buffer::set_data(const std::vector<T> &data, GLenum usage)
    {
        set_data(data.data(), data.size(), usage);
    }

    void Buffer::sub_data(GLintptr offset, GLsizeiptr size, const void *data)
    {
        glBufferSubData(m_type, offset, size, data);
    }

    template <typename T>
    void Buffer::sub_data(std::size_t index, const T *data, std::size_t size)
    {
        sub_data(index * sizeof(T), reinterpret_cast<const void *>(data), size * sizeof(T));
    }

    template <typename T>
    void Buffer::sub_data(std::size_t index, const std::vector<T> &data)
    {
        sub_data(index, data.data(), data.size());
    }

    Buffer::Type Buffer::get_type() const
    {
        return m_type;
    }

    void Buffer::bind()
    {
        glBindBuffer(m_type, data());
    }

    void Buffer::unbind()
    {
        glBindBuffer(m_type, 0);
    }

    void Buffer::delete_self()
    {
        if (!is_null())
            glDeleteBuffers(1, &data());
        data() = 0;
    }

    void Buffer::generate_id()
    {
        delete_self();
        check_type(m_type);
        glGenBuffers(1, &data());
        bind();
    }

    void Buffer::check_type(UInt32 type)
    {
        if (!(type == ARRAY_BUFFER ||
              type == ELEMENT_ARRAY_BUFFER))
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Buffer type error, value: ",
                    type));
    }

    void Buffer::check_id(GLuint id)
    {
        if (id == 0)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Buffer ID is a reserved value (is 0)"));

        if (glIsBuffer(id))
            return;
        throw std::runtime_error(
            to_string(
                TR_DEBUG,
                "The ID (value: ",
                id,
                ") is not a buffer"));
    }

} // namespace tr

#endif
