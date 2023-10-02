#include <iostream>
#include "../src/TR.hpp"

class MyApp : public tr::Application
{
private:
    tr::MaterialRes material;
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

        tr::ProgramRes program;
        program.create();
        TR_TRY(program->compile_from_file("shaders/base.vs", "shaders/base.fs"));

        std::vector<tr::DefaultVertex> vertices = {
            tr::DefaultVertex(),
        };

        tr::MaterialRes material;
        material.create(program);
    }

    void on_draw() override
    {
        clear_buffers();
        material->use_material();
        material->set_uniform("a", glm::vec2(1, 1));
    }
};

tr::Application &get_application()
{
    static MyApp app;
    return app;
}
