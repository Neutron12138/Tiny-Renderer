#ifndef TR_MESH_HPP
#define TR_MESH_HPP

#include <vector>
#include <glm/glm.hpp>
#include "Resource.hpp"
#include "ResourceHolder.hpp"
#include "Vertex.hpp"

namespace tr
{
    class VertexArray;

    template <typename T = Vertex>
    class Mesh : public Resource
    {
    public:
        using VertexType = T;
        using VertexContainer = std::vector<VertexType>;
        using SelfType = Mesh<VertexType>;
        using ParentType = Resource;

    private:
        VertexContainer m_vertices;

    public:
        Mesh(const VertexContainer &vertices = {});

    public:
        void set_vertices(const VertexContainer &vertices);
        VertexContainer &get_vertices();
        const VertexContainer &get_vertices() const;

        SelfType &set_vertex(std::size_t index, const VertexType &vertex);
        VertexType &get_vertex(std::size_t index);
        const VertexType &get_vertex(std::size_t index) const;

    public:
        virtual VertexArray generate_vertex_array() const;
    };

    template <typename T>
    using BasicMeshRes = Res<Mesh<T>>;

    using MeshRes = Res<Mesh<>>;

} // namespace tr

#endif
