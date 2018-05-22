#include "Display.h"

#include <memory>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

namespace Display
{
    std::unique_ptr<sf::RenderWindow> window;
    const uint16_t WIDTH = 640;
    const uint16_t HEIGHT = 480;

    void init()
    {
        sf::ContextSettings settings;
        settings.depthBits = 24; //RGB
        settings.majorVersion = 3;
        settings.minorVersion = 3; //OpenGL 3.3

        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT),
                                                    "Game", sf::Style::Close,
                                                    settings);

        glewInit();
        glViewport(0,0, WIDTH, HEIGHT);
    }

    void close()
    {
        window->close();
    }

    void clear()
    {
        glClearColor(0, 0, 0, 1.0);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    }

    void update()
    {
        window->display();
    }

    void checkForClose()
    {
        sf::Event e;
        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed) {
                close();
            }
        }
    }

    bool isOpen()
    {
        return window->isOpen();
    }
}
