#ifndef TR_UNIFORMNAMES_HPP
#define TR_UNIFORMNAMES_HPP

#include <vector>
#include <string>

namespace tr
{
    struct UniformNames
    {
        enum Names
        {
            VERTEX = 0,
            COLOR,
            NORMAL,
            TEX_COORD,

            CAMERA_POS,
            TIME,

            COUNT,
        };

        std::vector<std::string> names = {
            "a_vertex",
            "a_color",
            "a_normal",
            "a_texCoord",
            "u_camera_pos",
            "u_time",
        };
    };

} // namespace tr

#endif
