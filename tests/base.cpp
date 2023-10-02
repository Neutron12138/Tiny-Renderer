#include <iostream>
#include "../src/TR.hpp"

class MyApp : public tr::Application
{
private:
    tr::ProgramRes program;
    tr::VertexArrayRes va;

public:
    void on_created() override
    {
        tr::log.set_target(tr::Log::FILE);
        tr::log.get() << "Hello TR!" << std::endl;
        create_window(glm::ivec2(640, 480), "base");
        init_GL();
        tr::log.get() << "Initialized successfully!" << std::endl;

        tr::log.get() << std::endl;
        tr::log.get() << tr::get_text_from_file("base.cpp") << std::endl;
        tr::log.get() << tr::get_bytes_from_file("base.exe").data() << std::endl;
        tr::log.get() << std::endl;

        program.create();
        program->compile_from_file("shaders/base.vs", "shaders/base.fs");

        std::vector<tr::DefaultVertex> vertices = {
            tr::DefaultVertex(),
        };
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
