#ifndef TR_APPLICATION_CPP
#define TR_APPLICATION_CPP

#include "Application.hpp"
#include "Utils.hpp"

namespace tr
{
    int Application::run(int argc, char *argv[])
    {
        std::vector<std::string> args(argc);
        for (std::size_t i = 0; i < argc; i++)
            args[i] = argv[i];
        return run(args);
    }

    int Application::run(const std::vector<std::string> &args)
    {
        return run();
    }

    int Application::run()
    {
        TR_TRYS(
            m_window = std::make_unique<sf::RenderWindow>();
            on_created();

            m_last_time = get_current_clocks();
            while (get_window().isOpen()) {
                calc_delta_time();
                process_event();
                on_process(m_delta_time);
                on_draw();
                window_display();
            }

            on_destroyed(););

        return 0;
    }

    void Application::on_created()
    {
    }

    void Application::on_destroyed()
    {
    }

    void Application::on_draw()
    {
    }

    void Application::on_process(float delta_time)
    {
    }

    void Application::on_event(const sf::Event &event)
    {
        if (need_close(event))
            close_window();
    }

    sf::RenderWindow &Application::get_window()
    {
        if (m_window.operator bool())
            return *m_window;
        else
            throw std::runtime_error(
                to_string(TR_DEBUG, "Attempting to access a null pointer"));
    }

    const sf::RenderWindow &Application::get_window() const
    {
        if (m_window.operator bool())
            return *m_window;
        else
            throw std::runtime_error(
                to_string(TR_DEBUG, "Attempting to access a null pointer"));
    }

    void Application::create_window(
        const glm::ivec2 &size,
        const std::string &title,
        std::uint32_t style)
    {
        std::uint32_t attribute = sf::ContextSettings::Core | sf::ContextSettings::Debug;
        sf::ContextSettings settings(24, 8, 4, 4, 5, attribute, false);

        m_window->create(
            sf::VideoMode(size.x, size.y),
            title, style, settings);
    }

    void Application::create_window(
        const glm::ivec2 &size,
        const std::string &title,
        std::uint32_t style,
        const sf::ContextSettings &settings)
    {
        m_window->create(
            sf::VideoMode(size.x, size.y),
            title, style, settings);
    }

    void Application::close_window()
    {
        get_window().close();
    }

    void Application::window_display()
    {
        get_window().display();
    }

    void Application::process_event()
    {
        sf::Event event;
        while (get_window().pollEvent(event))
            on_event(event);
    }

    float Application::get_delta_time() const
    {
        return m_delta_time;
    }

    void Application::calc_delta_time()
    {
        float curr = get_current_clocks();
        m_delta_time = curr - m_last_time;
        m_last_time = curr;
    }

    void Application::clear_buffers(GLbitfield mask)
    {
        glClear(mask);
    }

    void Application::init_GL()
    {
        bool success = glewInit() == GLEW_OK;
        if (!success)
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Unable to initialize OpenGL"));
    }

    bool Application::need_close(const sf::Event &event)
    {
        if (event.type == sf::Event::Closed)
            return true;
        else if ((event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) &&
                 event.key.code == sf::Keyboard::Escape)
            return true;
        else
            return false;
    }

} // namespace tr

#endif
