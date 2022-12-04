#include "Asteroid.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <filesystem>
#include <ctime>
#include <random>



Asteroid::Asteroid()
{
	level = level;
}

Asteroid::~Asteroid()
{
}


bool Asteroid::IsAlive()
{
	return is_alive;
}


void Asteroid::Init(sf::Vector2u size)
{
	is_alive = true;
	level = 3;
	asteroid = asteroid;

	//set position
	sf::Vector2f position = SpawnPoints(size);
	asteroid.setPosition(position);
	std::cout << "x: " << position.x << " " << "y: " << position.y << std::endl;

	//set direction
	float angle = rand() % 360;
	std::cout << "angle:" << angle << std::endl;
	direction.x = -cos(m_math->Deg2Rad(angle));
	direction.y = sin(m_math->Deg2Rad(angle));
}

void Asteroid::Update(float deltaTime, sf::Vector2u size)
{
	if (!is_alive) return;

	speed = rand() % 1 + 0.05f;

	//std::cout << "x:" << direction.x << std::endl;
	//std::cout << "y:" << direction.y << std::endl;

	sf::Vector2f velocity = direction * speed * deltaTime;


	Wrap(size);
	asteroid.move(velocity);

}
void Asteroid::BreakDown(sf::Vector2u size, sf::Vector2f asteroid_pos)
{
	level--;

	if (level >= 0)
	{
		std::cout << level << std::endl;
	}

	if (level <= 0)
	{
		is_alive = false;
		return;
	}

	//resize
	sf::Vector2f asteroidSize = asteroid.getScale();
	asteroidSize.x = asteroidSize.x / 2;
	asteroidSize.y = asteroidSize.y / 2;
	asteroid.setScale(asteroidSize);
}

void Asteroid::AddNew_Asteroid(sf::Vector2f scale, sf::Vector2f asteroid_pos, int levelprev, float angle_prev)
{
	asteroid = asteroid;
	level = levelprev;

	if (level >= 0)
	{
		std::cout << level << std::endl;
	}

	if (level <= 0)
	{
		is_alive = false;
		return;
	}
	std::cout << "level: " << level << std::endl;

	//set scale
	scale.x = scale.x;
	scale.y = scale.y;
	asteroid.setScale(scale);


	//set position
	asteroid.setPosition(asteroid_pos);
	std::cout << "x: " << asteroid_pos.x << " " << "y: " << asteroid_pos.y << std::endl;

	//set direction
	angle = rand() % 360;
	if (angle >= angle_prev - 10 || angle <= angle_prev + 10)
		angle = rand() % 360;

	std::cout << "angle:" << angle << std::endl;

	direction.x = -cos(m_math->Deg2Rad(angle));
	direction.y = sin(m_math->Deg2Rad(angle));
}
int Asteroid::GetLevel()
{
	return level;
}
float Asteroid::GetAngle()
{
	return angle;
}
sf::Vector2f Asteroid::SpawnPoints(sf::Vector2u size)
{
	int max = 100;
	int min = 150;

	sf::Vector2f right;
	right.x = rand() % max + (size.x + 200);
	right.y = rand() % size.y;

	sf::Vector2f left;
	left.x = (rand() % max) - 250;
	left.y = rand() % size.y;

	sf::Vector2f top;
	top.y = (rand() % max) - 250;
	top.x = rand() % size.x;

	sf::Vector2f bottom;
	bottom.y = rand() % max + (size.y + 200);
	bottom.x = rand() % size.x;

	int choice = rand() % 4 + 1;

	switch (choice)
	{
	case 1:
		std::cout << "[Right] " << choice << std::endl;
		std::cout << "x: " << right.x << std::endl;
		std::cout << "y: " << right.y << std::endl;
		return right;
		break;

	case 2:
		std::cout << "[Left] " << choice << std::endl;
		std::cout << "x: " << left.x << std::endl;
		std::cout << "y: " << left.y << std::endl;
		return left;
		break;

	case 3:
		std::cout << "[Top] " << choice << std::endl;
		std::cout << "x: " << top.x << std::endl;
		std::cout << "y: " << top.y << std::endl;
		return top;
		break;

	case 4:
		std::cout << "[Bottom] " << choice << std::endl;
		std::cout << "x: " << bottom.x << std::endl;
		std::cout << "y: " << bottom.y << std::endl;
		return bottom;
		break;

	default:
		break;
	}

	return sf::Vector2f(0, 0);
}
void Asteroid::Draw(sf::RenderWindow &m_window)
{
	m_window.draw(asteroid);
}

//Private
void Asteroid::Wrap(sf::Vector2u size)
{
	sf::Vector2f positon;
	positon = asteroid.getPosition();

	if (positon.x < -160.f)
		positon.x = size.x + 100.f;
	else if (positon.x > size.x + 100.f)
		positon.x = -160.f;

	if (positon.y < -160.f)
		positon.y = size.y + 100.f;
	else if (positon.y > size.y + 100.f)
		positon.y = -160.f;

	asteroid.setPosition(positon);
}