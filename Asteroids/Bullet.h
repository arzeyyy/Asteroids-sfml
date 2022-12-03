#pragma once

#include <SFML/Graphics.hpp>

#include "Math.h"

class Bullet
{
	static const float lifetime;
	static const float speed;

public:
	sf::RectangleShape bullet;

	//sf::SoundBuffer fire_sfx;
	//sf::Sound sound;

	Bullet();
	~Bullet();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &m_window);
	bool isAlive();
	void Init(sf::Vector2f position, float angle);
	void Kill();

private:
	Math *m_math;

	sf::Vector2f size;
	sf::Vector2f position;
	sf::Vector2f direction;

	bool is_alive;
	float remaining_life;

};
