#ifndef TR_PROGRAM_HPP
#define TR_PROGRAM_HPP

#include "Shader.hpp"

namespace tr
{
    class Program : public Resource<GLuint>
    {
    private:
        std::vector<ShaderRes> m_attached_shaders;

    public:
        Program();
        Program(GLuint id);
        ~Program();

    public:
        GLuint get_id() const;
        bool is_null() const;

    public:
        void attach_shaders(const std::vector<ShaderRes> &shaders);
        void load_from_string(const std::string &vsource, const std::string &fsource);
        void load_from_string(const std::string &vsource, const std::string &fsource, const std::string &gsource);

    public:
        static void check_id(GLuint id);
        static void check_error(GLuint id);
    };

} // namespace tr

#endif
