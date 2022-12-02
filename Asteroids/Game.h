#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Level.h"

#include <memory>

class Game
{
private:
	sf::RenderWindow *m_window;
	sf::Clock clock;

	//Level *m_level = new Level();

public:
	Game();

	void Run();
};


