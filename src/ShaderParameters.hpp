#ifndef TR_SHADERPARAMETERS_HPP
#define TR_SHADERPARAMETERS_HPP

#include <vector>
#include <string>
#include <glm/glm.hpp>
#include "Program.hpp"

namespace tr
{
    class ShaderParameters
    {
    public:
        template <typename T>
        struct Attribute
        {
            using NameType = std::string;
            using ValueType = T;

            NameType name;
            ValueType value = {};
            bool use = false;
        };

        template <typename T>
        struct Uniform
        {
            using NameType = std::string;
            using ValueType = T;

            NameType name;
            ValueType value = {};
        };

        enum DefaultLocation : UInt32
        {
            POSITION = 0,
            COLOR = 1,
            NORMAL = 2,
            TEX_COORD = 3,
        };

    public:
        Attribute<glm::vec3> position = {"a_position"};
        Attribute<glm::vec4> color = {"a_color"};
        Attribute<glm::vec3> normal = {"a_normal"};
        Attribute<glm::vec2> texCoord = {"a_texCoord"};

        Uniform<glm::mat4> projection = {"u_projection", glm::mat4(1.0f)};
        Uniform<glm::mat4> view = {"u_view", glm::mat4(1.0f)};
        Uniform<glm::mat4> model = {"u_model", glm::mat4(1.0f)};
        Uniform<glm::mat4> VP = {"u_VP", glm::mat4(1.0f)};
        Uniform<glm::mat4> MVP = {"u_MVP", glm::mat4(1.0f)};

        Uniform<glm::vec3> camera_pos = {"u_camera_pos"};
    };

    using ShaderParametersRes = Res<ShaderParameters>;

} // namespace tr

#endif
