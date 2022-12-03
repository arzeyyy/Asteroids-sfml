#include "Player.h"

#include <iostream>

const float Player::acceleration = 1.75f;
const sf::Vector2f Player::max_velocity = sf::Vector2f(2.5f, 2.5f);
const float Player::rotateSpeed = 0.3f;



Player::Player()
{
	std::cout << "Player created" << std::endl;

	h_move = 0;
	v_move = 0;
}

Player::~Player()
{
}

bool Player::IsAlive() 
{
	return is_alive;
}

void Player::Kill()
{
	is_alive = false;
}

void Player::Init(sf::Vector2u size)
{
	is_alive = true;

	//set assets
	m_assets.SetTexture("player", "Assets/Textures/asteroids_player.png");
	player.setTexture(m_assets.GetTexture("player"));

	m_assets.SetBuffer("thrust", "Assets/sound/thrust.wav");
	sound.setBuffer(m_assets.GetBuffer("thrust"));
	

	//set size
	const sf::Vector2f spriteSize(
		player.getTexture()->getSize().x * player.getScale().x,
		player.getTexture()->getSize().y * player.getScale().y);

	//set position and center origin
	player.setPosition(size.x / 2, size.y / 2);
	player.setOrigin(player.getLocalBounds().width / 2, player.getLocalBounds().height / 2);
}


void Player::Draw(sf::RenderWindow &m_window)
{
	m_window.draw(player);
}

void Player::OnEvent(const sf::Event event)
{
	h_move = 0;
	v_move = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		v_move = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		v_move = -1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		h_move = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		h_move = -1;
}

void Player::Update(float deltaTime, sf::Vector2u size)
{
	if (!is_alive) return;

	if (h_move != 0)
	{
		player.rotate(h_move * rotateSpeed * deltaTime);
	}

	if (v_move != 0)
	{
		if (play_thrust == false)
		{
			play_thrust = true;
			MovePlay();
		}
		float rotation = player.getRotation();

		x_dir = -cos(m_math->Deg2Rad(rotation));
		y_dir = -sin(m_math->Deg2Rad(rotation));

		velocity.x += v_move * acceleration * deltaTime * x_dir / 1000;
		velocity.y += v_move * acceleration * deltaTime * y_dir / 1000;

		//mag = m_math->Magnitude(velocity.x, velocity.y);
		//velocity.x = velocity.x / mag;
		//velocity.y = velocity.y / mag;

		if ((velocity.x * velocity.x) > (max_velocity.x * max_velocity.x))
			velocity.x = velocity.x > 0 ? max_velocity.x : -max_velocity.x;

		if ((velocity.y * velocity.y) > (max_velocity.y * max_velocity.y))
			velocity.y = velocity.y > 0 ? max_velocity.y : -max_velocity.y;
	}
	else
	{
		play_thrust = false;
		MoveStop();
	}

	sf::Vector2f positon;
	positon = player.getPosition();

	if (positon.x < -10.f)
		positon.x = size.x;
	else if (positon.x > size.x)
		positon.x = 0.0f;

	if (positon.y < -10.f)
		positon.y = size.y;
	else if (positon.y > size.y)
		positon.y = 0.0f;

	//std::cout << velocity.x << std::endl;
	//std::cout << velocity.y << std::endl;

	player.setPosition(positon);
	player.move(velocity);

}

void Player::MovePlay()
{
	sound.setVolume(45);
	sound.setLoop(true);
	sound.play();
}
void Player::MoveStop()
{
	sound.setVolume(0);
	sound.stop();
}
