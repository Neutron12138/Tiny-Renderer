#ifndef TR_DEBUGMESSAGER_CPP
#define TR_DEBUGMESSAGER_CPP

#include "DebugMessager.hpp"

namespace tr
{
    void GLAPIENTRY _debug_message_callback(
        GLenum source, GLenum type, GLuint id, GLenum severity,
        GLsizei length, const GLchar *message, const void *userParam)
    {
        if (_debug_messager.operator bool())
            _debug_messager.operator()(source, type, id, severity, length, message, userParam);
    }

    void register_debug_message_callback(
        const std::function<DebugMessageCallback> &callback, const void *userParam)
    {
        _debug_messager = callback;
        glDebugMessageCallback(_debug_message_callback, userParam);
    }

    void DebugMessager::operator()(
        GLenum source, GLenum type, GLuint id, GLenum severity,
        GLsizei length, const GLchar *message, const void *userParam)
    {
        log.get() << "--------------------" << std::endl
                  << "source : " << glenum_to_string(source) << std::endl
                  << "type : " << glenum_to_string(type) << std::endl
                  << "id : " << glenum_to_string(id) << std::endl
                  << "severity : " << glenum_to_string(severity) << std::endl
                  << "length : " << length << std::endl
                  << "message : " << message << std::endl
                  << "userParam : " << userParam << std::endl;
    }

} // namespace tr

#endif
