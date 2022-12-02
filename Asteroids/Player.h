#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Math.h"


class Player
{
public:
	Player();
	~Player();

	float x_dir;
	float y_dir;

	sf::Sprite player;
	void Draw(sf::RenderWindow &m_window);
	void OnEvent(const sf::Event event);
	void Init(sf::Vector2u size);
	void Update(float deltaTime, sf::Vector2u size);


private:
	sf::Texture texture;
	sf::SoundBuffer thrust_sf;
	sf::Sound sound;

	bool play_thrust;
	bool play_one = false;

	static const float acceleration;
	static const float rotateSpeed;
	static const sf::Vector2f max_velocity;

	int v_move, h_move;

	Math *m_math;
	sf::Vector2f velocity;
	sf::Vector2f u_velocity;
	float mag;

	void MovePlay();
	void MoveStop();
};



