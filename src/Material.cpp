#ifndef TR_MATERIAL_CPP
#define TR_MATERIAL_CPP

#include "Material.hpp"

#define TR_MATERIAL_SET_UNIFORM_VEC1_IMPL(valtype, func)               \
    void Material::set_uniform(GLint location, valtype value)          \
    {                                                                  \
        func(location, value);                                         \
    }                                                                  \
                                                                       \
    void Material::set_uniform(const std::string &name, valtype value) \
    {                                                                  \
        set_uniform(m_program->get_uniform_location(name), value);     \
    }

#define TR_MATERIAL_SET_UNIFORM_VEC2_IMPL(vectype, valtype, func)               \
    void Material::set_uniform(GLint location, const vectype &value)            \
    {                                                                           \
        func(location, value.x, value.y);                                       \
    }                                                                           \
                                                                                \
    void Material::set_uniform(const std::string &name, const vectype &value)   \
    {                                                                           \
        set_uniform(m_program->get_uniform_location(name), value);              \
    }                                                                           \
                                                                                \
    void Material::set_uniform(GLint location, valtype v0, valtype v1)          \
    {                                                                           \
        func(location, v0, v1);                                                 \
    }                                                                           \
                                                                                \
    void Material::set_uniform(const std::string &name, valtype v0, valtype v1) \
    {                                                                           \
        set_uniform(m_program->get_uniform_location(name), v0, v1);             \
    }

namespace tr
{
    Material::Material(const ProgramRes &program)
        : m_program(program) {}

    Material::Material(const ProgramRes &program, const ShaderParametersRes &parameters)
        : m_program(program), m_parameters(parameters) {}

    const ProgramRes &Material::get_program() const
    {
        return m_program;
    }

    const ShaderParametersRes &Material::get_parameters() const
    {
        return m_parameters;
    }

    void Material::use_material()
    {
        if (m_program.is_nullptr())
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Program cannot be a null pointer"));

        m_program->use_program();
    }

    void Material::update_parameters()
    {
        if (m_program.is_nullptr())
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Shader Parameters cannot be a null pointer"));
    }

    // 一维数据

    TR_MATERIAL_SET_UNIFORM_VEC1_IMPL(GLint, glUniform1i);
    TR_MATERIAL_SET_UNIFORM_VEC1_IMPL(GLuint, glUniform1ui);
    TR_MATERIAL_SET_UNIFORM_VEC1_IMPL(GLfloat, glUniform1f);
    TR_MATERIAL_SET_UNIFORM_VEC1_IMPL(GLdouble, glUniform1d);

    // 二维数据

    TR_MATERIAL_SET_UNIFORM_VEC2_IMPL(glm::ivec2, GLint, glUniform2i);
    TR_MATERIAL_SET_UNIFORM_VEC2_IMPL(glm::uvec2, GLuint, glUniform2ui);
    TR_MATERIAL_SET_UNIFORM_VEC2_IMPL(glm::vec2, GLfloat, glUniform2f);
    TR_MATERIAL_SET_UNIFORM_VEC2_IMPL(glm::dvec2, GLdouble, glUniform2d);

} // namespace tr

#endif
