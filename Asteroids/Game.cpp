#include "Game.h"
#include <iostream>

#include "Level.h"


Game::Game()
{
    m_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Asteroids", sf::Style::Close);

}

void Game::Run()
{


    Level level;
    sf::Clock clock;

    level.Init(m_window->getSize());
    m_window->setFramerateLimit(120);

    while (m_window->isOpen())
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window->close();
            }
            level.onEvent(event);
        }

        m_window->clear();

        level.update(clock.restart().asMilliseconds(), m_window->getSize());

        level.Draw(*m_window);

        m_window->display();
    }
}



