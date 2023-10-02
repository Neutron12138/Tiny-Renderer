#ifndef TR_VERTEXARRAY_HPP
#define TR_VERTEXARRAY_HPP

#include "GLResource.hpp"
#include "Buffer.hpp"
#include "ResourceHolder.hpp"

namespace tr
{
    class VertexArray : public Bindable
    {
    public:
        using BufferContainer = std::vector<BufferRes>;
        using ParentType = Bindable;

    private:
        BufferContainer m_buffers;

    public:
        VertexArray(GLuint id = 0);
        ~VertexArray();

    public:
        const BufferContainer &get_buffers() const;

    public:
        void bind_buffer(const BufferRes &buffer);
        void bind_buffers(const BufferContainer &buffers);

    public:
        void bind() override;
        void unbind() override;
        void delete_self() override;
        void generate_id() override;

    public:
        static void check_id(GLuint id);
    };

    using VertexArrayRes = Res<VertexArray>;

} // namespace tr

#endif
