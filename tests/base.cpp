#include <iostream>
#include "../src/TR.hpp"

class MyApp : public tr::Application
{
public:
    void on_created() override
    {
        tr::log.set_target(tr::Log::FILE);
        tr::log.get() << "Hello TR!" << std::endl;
        create_window(glm::ivec2(640, 480), "base");
        init_GL();
        tr::log.get() << "Initialized successfully!" << std::endl;
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
