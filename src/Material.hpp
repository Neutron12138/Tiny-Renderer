#ifndef TR_MATERIAL_HPP
#define TR_MATERIAL_HPP

#include <glm/glm.hpp>
#include "Program.hpp"
#include "ShaderParameters.hpp"
#include "Utils.hpp"

#define TR_MATERIAL_SET_UNIFORM_VEC1(type)        \
    void set_uniform(GLint location, type value); \
    void set_uniform(const std::string &name, type value);

#define TR_MATERIAL_SET_UNIFORM_VEC2(vectype, valtype)               \
    void set_uniform(GLint location, const vectype &value);          \
    void set_uniform(const std::string &name, const vectype &value); \
    void set_uniform(GLint location, valtype v0, valtype v1);        \
    void set_uniform(const std::string &name, valtype v0, valtype v1);

namespace tr
{
    class Material
    {
    private:
        ProgramRes m_program;
        ShaderParametersRes m_parameters;

    public:
        Material(const ProgramRes &program);
        Material(const ProgramRes &program, const ShaderParametersRes &parameters);

    public:
        const ProgramRes &get_program() const;
        const ShaderParametersRes &get_parameters() const;

    public:
        virtual void use_material();
        virtual void update_parameters();

    public:
        // 一维数据
        TR_MATERIAL_SET_UNIFORM_VEC1(GLint);
        TR_MATERIAL_SET_UNIFORM_VEC1(GLuint);
        TR_MATERIAL_SET_UNIFORM_VEC1(GLfloat);
        TR_MATERIAL_SET_UNIFORM_VEC1(GLdouble);

        // 二维数据
        TR_MATERIAL_SET_UNIFORM_VEC2(glm::ivec2, GLint);
        TR_MATERIAL_SET_UNIFORM_VEC2(glm::uvec2, GLuint);
        TR_MATERIAL_SET_UNIFORM_VEC2(glm::vec2, GLfloat);
        TR_MATERIAL_SET_UNIFORM_VEC2(glm::dvec2, GLdouble);
    };

    using MaterialRes = Res<Material>;

} // namespace tr

#endif
