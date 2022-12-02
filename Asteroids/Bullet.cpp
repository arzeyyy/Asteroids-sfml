#include "Bullet.h"


#include <iostream>

const float Bullet::lifetime = 2200.f;
const float Bullet::speed = 180.f;

Bullet::Bullet()
{
	//direction.x = -cos(m_math->Deg2Rad(angle));
	//direction.y = -sin(m_math->Deg2Rad(angle));

}


Bullet::~Bullet()
{
}

void Bullet::Init(sf::Vector2f position, float angle) // of player
{
	if (!fire_sfx.loadFromFile("Assets/sound/fire.wav"))
		std::cout << "cannot load fire sound";

	sound.setBuffer(fire_sfx);
	sound.play();

	is_alive = true;
	remaining_life = lifetime;
	size = sf::Vector2f(5.f, 5.f);

	direction.x = -cos(m_math->Deg2Rad(angle));
	direction.y = -sin(m_math->Deg2Rad(angle));

	position.x += 14.f * direction.x;
	position.y += 14.f * direction.y;


	bullet.setPosition(position);
	bullet.setSize(size);
	bullet.setFillColor(sf::Color::White);
}


void Bullet::Kill()
{
	is_alive = false;
}

bool Bullet::isAlive()
{
	return is_alive;
}

void Bullet::Update(float deltaTime)
{
	if (!is_alive) return;

	remaining_life -= deltaTime;
	if (remaining_life <= 0)
	{
		is_alive = false;
	}


	sf::Vector2f distance = direction * speed * deltaTime / 1000.f;

	//std::cout << "x: " << direction.x << std::endl;
	//std::cout << "y: " << direction.y << std::endl;

	bullet.move(distance);
}

void Bullet::Draw(sf::RenderWindow &m_window)
{
	m_window.draw(bullet);
}
