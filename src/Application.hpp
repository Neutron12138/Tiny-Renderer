#ifndef TR_APPLICATION_HPP
#define TR_APPLICATION_HPP

#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <cstdint>
#include <GL/glew.h>

namespace tr
{
    class Application
    {
    private:
        std::unique_ptr<sf::RenderWindow> m_window;
        float m_last_time = 0.0f;
        float m_delta_time = 0.0f;

    public:
        virtual int run(int argc, char *argv[]);
        virtual int run(const std::vector<std::string> &args);
        virtual int run();

        virtual void on_created();
        virtual void on_destroyed();
        virtual void on_draw();
        virtual void on_process(float delta_time);
        virtual void on_event(const sf::Event &event);

    public:
        sf::RenderWindow &get_window();
        const sf::RenderWindow &get_window() const;

    public:
        float get_delta_time() const;
        void calc_delta_time();

    public:
        void create_window(const glm::ivec2 &size,
                           const std::string &title,
                           std::uint32_t style = sf::Style::Default);
        void create_window(const glm::ivec2 &size,
                           const std::string &title,
                           std::uint32_t style,
                           const sf::ContextSettings &settings);
        void close_window();
        void window_display();
        void process_event();
        void clear_buffers(GLbitfield mask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    public:
        static void init_GL();
    };

} // namespace tr

#endif
