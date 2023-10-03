#ifndef TR_VERTEX_HPP
#define TR_VERTEX_HPP

#include <glm/glm.hpp>

namespace tr
{
    template <typename T = glm::vec3>
    struct TR_ALIGN VertexPosition
    {
        using PositionType = T;
        T position = {};

        VertexPosition(const PositionType &pos = {})
            : position(pos) {}
    };

    template <typename T = glm::vec4>
    struct TR_ALIGN VertexColor
    {
        using ColorType = T;
        T color = {};

        VertexColor(const ColorType &col = {})
            : color(col) {}
    };

    struct TR_ALIGN VertexNormal
    {
        using NormalType = glm::vec3;
        glm::vec3 normal = {};

        VertexNormal(const NormalType &nor = {})
            : normal(nor) {}
    };

    template <typename T = glm::vec2>
    struct TR_ALIGN VertexTexCoord
    {
        using TexCoordType = T;
        T texCoord = {};

        VertexTexCoord(const TexCoordType &tex = {})
            : texCoord(tex) {}
    };

    struct TR_ALIGN BasicVertex
    {
    };

    struct Vertex
        : public BasicVertex,
          public VertexPosition<>,
          public VertexColor<>,
          public VertexNormal,
          public VertexTexCoord<>
    {
    public:
        using PositionParent = VertexPosition<glm::vec3>;
        using ColorParent = VertexColor<glm::vec4>;
        using NormalParent = VertexNormal;
        using TexCoordParent = VertexTexCoord<glm::vec2>;

        using PositionType = glm::vec3;
        using ColorType = glm::vec4;
        using NormalType = glm::vec3;
        using TexCoordType = glm::vec2;

    public:
        Vertex(const PositionType &position = {});
        Vertex(const PositionType &position, const ColorType &color);
        Vertex(const PositionType &position, const NormalType &normal);
        Vertex(const PositionType &position, const TexCoordType &texCoord);
        Vertex(const PositionType &position, const ColorType &color,
                      const NormalType &normal, const TexCoordType &texCoord);
    };

} // namespace tr

#endif
