#ifndef TR_MATERIAL_HPP
#define TR_MATERIAL_HPP

#include "Program.hpp"
#include "ShaderParameters.hpp"

namespace tr
{
    class Material
    {
    private:
        ProgramRes m_program;
        ShaderParametersRes m_parameters;
    };

} // namespace tr

#endif
