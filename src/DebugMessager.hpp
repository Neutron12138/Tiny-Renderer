#ifndef TR_DEBUGMESSAGER_HPP
#define TR_DEBUGMESSAGER_HPP

#include <functional>
#include <GL/glew.h>
#include "Utils.hpp"
#include "Log.hpp"

namespace tr
{
    using DebugMessageCallback =
        void(GLenum source, GLenum type, GLuint id, GLenum severity,
             GLsizei length, const GLchar *message, const void *userParam);

    TR_DLL std::function<DebugMessageCallback> _debug_messager;
    void GLAPIENTRY _debug_message_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);

    void register_debug_message_callback(const std::function<DebugMessageCallback> &callback, const void *userParam = nullptr);

    class DebugMessager
    {
    public:
        virtual void operator()(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
    };

} // namespace tr

#endif
