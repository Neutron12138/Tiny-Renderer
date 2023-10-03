#ifndef TR_MESH_HPP
#define TR_MESH_HPP

#include <vector>
#include <glm/glm.hpp>
#include "Resource.hpp"
#include "ResourceHolder.hpp"
#include "Vertex.hpp"
#include "VertexArray.hpp"
#include "ShaderParameters.hpp"
#include "VertexBuffer.hpp"

#define TR_MESH_CHECK_INDEX                     \
    if (index >= m_vertices.size())             \
        throw std::runtime_error(               \
            to_string(                          \
                TR_DEBUG,                       \
                "Index out of bounds, index: ", \
                index,                          \
                ", size: ",                     \
                m_vertices.size()));

namespace tr
{
    template <typename T>
    class BasicMesh : public Resource
    {
    public:
        using VertexType = T;
        using VertexContainer = std::vector<VertexType>;
        using SelfType = BasicMesh<VertexType>;
        using ParentType = Resource;

    private:
        VertexContainer m_vertices;

    public:
        BasicMesh(const VertexContainer &vertices = {})
            : m_vertices(vertices) {}

    public:
        SelfType &set_vertices(const VertexContainer &vertices)
        {
            m_vertices = vertices;
            return *this;
        }

        VertexContainer &get_vertices()
        {
            return m_vertices;
        }

        const VertexContainer &get_vertices() const
        {
            return m_vertices;
        }

        SelfType &set_vertex(std::size_t index, const VertexType &vertex)
        {
            TR_MESH_CHECK_INDEX;
            m_vertices[index] = vertex;

            return *this;
        }

        VertexType &get_vertex(std::size_t index)
        {
            TR_MESH_CHECK_INDEX;
            return m_vertices[index];
        }

        const VertexType &get_vertex(std::size_t index) const
        {
            TR_MESH_CHECK_INDEX;
            return m_vertices[index];
        }

        VertexType &operator[](std::size_t index)
        {
            TR_MESH_CHECK_INDEX;
            return m_vertices[index];
        }

        const VertexType &operator[](std::size_t index) const
        {
            TR_MESH_CHECK_INDEX;
            return m_vertices[index];
        }
    };

    template <typename T>
    class Mesh : public BasicMesh<T>
    {
    public:
        using VertexType = T;
        using VertexContainer = std::vector<VertexType>;
        using SelfType = Mesh<VertexType>;
        using ParentType = BasicMesh<VertexType>;

    public:
        virtual VertexArrayRes generate_vertex_array(GLenum usage = GL_STATIC_DRAW) const = 0;
    };

    template <>
    class Mesh<Vertex> : public BasicMesh<Vertex>
    {
    public:
        using VertexType = Vertex;
        using SelfType = Mesh<VertexType>;
        using ParentType = BasicMesh<VertexType>;

    public:
        Mesh(const VertexContainer &vertices = {});

    public:
        virtual VertexArrayRes generate_vertex_array(GLenum usage = GL_STATIC_DRAW) const;
    };

    template <typename T>
    using MeshRes = Res<Mesh<T>>;

    using DefaultMesh = Mesh<Vertex>;
    using DefaultMeshRes = Res<DefaultMesh>;

} // namespace tr

#endif
