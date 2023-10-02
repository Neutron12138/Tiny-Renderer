#ifndef TR_VERTEX_HPP
#define TR_VERTEX_HPP

#include <glm/glm.hpp>

namespace tr
{
    template <typename T = glm::vec3>
    struct VertexPosition
    {
        using PositionType = T;
        T position = {};
    };

    template <typename T = glm::vec4>
    struct VertexColor
    {
        using ColorType = T;
        T color = {};
    };

    struct VertexNormal
    {
        glm::vec3 normal = {};
    };

    template <typename T = glm::vec2>
    struct VertexTexCoord
    {
        using TexCoordType = T;
        T texCoord = {};
    };

    struct TR_ALIGN Vertex
    {
    };

    struct DefaultVertex
        : public Vertex,
          public VertexPosition<>,
          public VertexColor<>,
          public VertexNormal,
          public VertexTexCoord<>
    {
    };

} // namespace tr

#endif
