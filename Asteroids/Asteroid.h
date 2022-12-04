#pragma once

#include <SFML/Graphics.hpp>

#include "Math.h"

class Asteroid
{
public:
	sf::Sprite asteroid;

	//functions
	Asteroid(sf::Vector2u size, sf::Vector2f asteroid_pos);
	Asteroid(sf::Vector2f position, float angle, int level);
	Asteroid();
	~Asteroid();
	bool IsAlive();
	void Init(sf::Vector2u size);
	void Update(float deltaTime, sf::Vector2u size);
	void BreakDown(sf::Vector2u size, sf::Vector2f asteroid_pos);
	void AddNew_Asteroid(sf::Vector2f size_prev, sf::Vector2f asteroid_pos, int levelprev, float angle_prev);
	void Draw(sf::RenderWindow &m_window);
	int GetLevel();
	float GetAngle();
	sf::Vector2f SpawnPoints(sf::Vector2u size);


private:
	Math *m_math;
	sf::Vector2f direction;

	float speed;
	float angle;
	bool is_alive;
	int level;
	//functions
	void Wrap(sf::Vector2u size);


};

