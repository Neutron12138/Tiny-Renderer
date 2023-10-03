#ifndef TR_MESH_CPP
#define TR_MESH_CPP

#include "Mesh.hpp"

namespace tr
{
    Mesh<Vertex>::Mesh(const VertexContainer &vertices)
        : ParentType(vertices) {}

    VertexArrayRes Mesh<Vertex>::generate_vertex_array(GLenum usage) const
    {
        const std::size_t s3f = sizeof(glm::vec3);
        const std::size_t s4f = sizeof(glm::vec4);
        const VertexContainer &vertices = get_vertices();

        VertexBufferRes vb;
        vb.create();
        vb->generate_id();
        vb->bind();
        vb->set_data(vertices, usage);

        vb->enable_vertex_attrib_array(ShaderParameters::POSITION);
        vb->vertex_attrib_pointer(ShaderParameters::POSITION, 3, sizeof(Vertex), 0);
        vb->enable_vertex_attrib_array(ShaderParameters::COLOR);
        vb->vertex_attrib_pointer(ShaderParameters::COLOR, 4, sizeof(Vertex), s3f);
        vb->enable_vertex_attrib_array(ShaderParameters::NORMAL);
        vb->vertex_attrib_pointer(ShaderParameters::NORMAL, 3, sizeof(Vertex), s3f + s4f);
        vb->enable_vertex_attrib_array(ShaderParameters::TEX_COORD);
        vb->vertex_attrib_pointer(ShaderParameters::TEX_COORD, 2, sizeof(Vertex), s3f + s4f + s3f);

        VertexArrayRes va;
        va.create();
        va->generate_id();
        va->bind();
        va->bind_buffer(vb);
        va->unbind();

        vb->unbind();

        return va;
    }

} // namespace tr

#endif
