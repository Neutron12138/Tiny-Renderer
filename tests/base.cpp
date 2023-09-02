#include <iostream>
#include "../src/TR.hpp"

class MyApp : public tr::Application
{
public:
    void on_created() override
    {
        tr::log.set_target(tr::Log::FILE);
        create_window(glm::ivec2(640, 480), "base");
        init_GL();

        tr::log.get() << "Hello TR!" << std::endl;

        tr::run_gl_function<GLuint, GLenum>(glCreateShader, 0);
    }

    void on_draw() override
    {
        clear_buffers();
    }
};

tr::Application &get_application()
{
    static MyApp app;
    return app;
}
