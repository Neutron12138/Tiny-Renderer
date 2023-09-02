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

        tr::NamesInShader n;
        for (size_t i = 0; i < n.names.size(); i++)
            std::cout << i << ":" << n.names.at(i) << std::endl;
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
