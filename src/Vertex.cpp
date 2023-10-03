#ifndef TR_VERTEX_CPP
#define TR_VERTEX_CPP

#include "Vertex.hpp"

namespace tr
{
    Vertex::Vertex(const PositionType &pos)
        : PositionParent(pos) {}

    Vertex::Vertex(const PositionType &pos, const ColorType &col)
        : PositionParent(pos), ColorParent(col) {}

    Vertex::Vertex(const PositionType &pos, const NormalType &nor)
        : PositionParent(pos), NormalParent(nor) {}

    Vertex::Vertex(const PositionType &pos, const TexCoordType &tex)
        : PositionParent(pos), TexCoordParent(tex) {}

    Vertex::Vertex(const PositionType &pos, const ColorType &col,
                                 const NormalType &nor, const TexCoordType &tex)
        : PositionParent(pos), ColorParent(col), NormalParent(nor), TexCoordParent(tex) {}

} // namespace tr

#endif
