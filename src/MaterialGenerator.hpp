#ifndef TR_MATERIALGENERATOR_HPP
#define TR_MATERIALGENERATOR_HPP

#include <glm/glm.hpp>
#include "BasicType.hpp"

namespace tr
{
    class Material;

    class MaterialGenerator
    {
    public:
        struct Color
        {
            enum Source : EnumT
            {
                WHITE = 0,
                BLACK,
                ATTRIBUTE,
                UNIFORM,
                TEXTURE,
                TEXTURES_ADDED,
                TEXTURES_MIXED,

                COUNT,
            };

            Source source = WHITE;
            glm::vec4 color;
        };

        struct Lighting
        {
            enum Mode : EnumT
            {
                DISABLED = 0,
                LIGHTING,
                DOUBLE_LIGHTING,

                MODE_COUNT,
            };

            enum Algorithm : EnumT
            {
                AMBIENT = 0x1 << 0,
                DIFFUSE = 0x1 << 1,
                SPECULAR = 0x1 << 2,

                PHONG = 0x0 << 3,
                GOURAUD = 0x1 << 3,

                ALGORITHM_COUNT,
            };

            Mode mode = DISABLED;
            Algorithm algorithm;
        };

    public:
        Color color;
        Lighting lighting;

    public:
        virtual Material generate_material();
    };

} // namespace tr

#endif
