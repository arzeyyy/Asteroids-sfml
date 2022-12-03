#include "Level.h"

#include <iostream>
#include <string>

const float Level::timeBetweenShots = 200.f;

Level::Level()
{

}

Level::~Level()
{
}
void Level::Init(sf::Vector2u size)
{
	m_player.Init(size);

	//Score(score);
	score = 0;
	m_assets.SetFont("Score_fnt", "Assets/fonts/digital-7.ttf");
	score_text.setFont(m_assets.GetFont("Score_fnt"));
	score_text.setCharacterSize(38);
	score_text.setString(std::to_string(score));
	score_text.setOrigin(score_text.getLocalBounds().width / 2, score_text.getLocalBounds().height / 2);
	score_text.setPosition(20, 20);
	score_text.setFillColor(sf::Color::White);

	//load Asteroid textures
	m_assets.SetTexture("Asteroid0", "Assets/Textures/Asteroid1.png");
	m_assets.SetTexture("Asteroid1", "Assets/Textures/Asteroid2.png");
	m_assets.SetTexture("Asteroid2", "Assets/Textures/Asteroid3.png");

	//load Asteroid sounds
	std::string explosions_path[3] = { "Assets/sound/bangSmall.wav",
									   "Assets/sound/bangMedium.wav",
									   "Assets/sound/bangLarge.wav" };

	m_assets.SetBuffer("explosion0", explosions_path[0]);
	m_assets.SetBuffer("explosion1", explosions_path[1]);
	m_assets.SetBuffer("explosion2", explosions_path[2]);

	//load Bullet sounds
	m_assets.SetBuffer("fire", "Assets/sound/fire.wav");
	bullet_sound.setBuffer(m_assets.GetBuffer("fire"));

	bullet_sound.setVolume(65);
	asteroids_sound.setVolume(65);

}

void Level::onEvent(const sf::Event &event)
{
	m_player.OnEvent(event);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (timer >= 0) return;
		timer = timeBetweenShots;

		m_bullet.Init(m_player.player.getPosition(), m_player.player.getRotation());
		bullet_sound.play();
		m_bullets.push_back(m_bullet);
		std::cout << "bullet created" << std::endl;
	}
}

void Level::update(float deltaTime, sf::Vector2u size)
{
	timer -= deltaTime;
	m_player.Update(deltaTime, size);


	//std::cout << m_asteroids.size() << std::endl;
	if (m_asteroids.size() <= 10)
	{
		for (int i = 0; i < rand() % 2; i++)
		{
			m_asteroid.SpawnPoints(size);
			//set texture
			AsteroidTexture();
			m_asteroid.Init(size);
			m_asteroids.push_back(m_asteroid);
			std::cout << "asteroid created" << std::endl;
		}
	}

	//update bullets & asteroids
	for (int i = 0; i < m_asteroids.size(); i++)
	{
		for (int j = 0; j < m_bullets.size(); j++)
		{
			if (m_bullets[j].isAlive())
			{
				//collisions bullet-asteroids
				if (!m_bullets[j].bullet.getGlobalBounds().intersects(m_asteroids[i].asteroid.getGlobalBounds()))
				{
					m_bullets[j].Update(deltaTime);

				}
				else
				{
					m_bullets[j].Kill();
					m_asteroids[i].BreakDown(size, m_asteroids[i].asteroid.getPosition());
					m_asteroids.push_back(m_asteroid);
					m_asteroids[m_asteroids.size() - 1].AddNew_Asteroid(m_asteroids[i].asteroid.getScale(), m_asteroids[i].asteroid.getPosition(), m_asteroids[i].GetLevel(), m_asteroids[i].GetAngle());
					AsteroidSound(i);

					//increment score
					score += 20;
					score_text.setString(std::to_string(score));

				}
			}
		}
		//collisions player-asteroids
		if (m_asteroids[i].asteroid.getGlobalBounds().intersects(m_player.player.getGlobalBounds()))
		{
			//m_player.Kill();
		}

		//asteroids update
		if (m_asteroids[i].IsAlive())
		{
			m_asteroids[i].Update(deltaTime, size);
		}
		else
		{
			m_asteroids.erase(m_asteroids.begin() + i);
		}
	}
}

void Level::Draw(sf::RenderWindow &m_window)
{
	m_window.draw(score_text);

	if (m_player.IsAlive())
	{
		m_player.Draw(m_window);
	}
	//draw asteroids
	for (int i = 0; i < m_asteroids.size(); i++)
	{
		if (m_asteroids[i].IsAlive())
		{
			m_asteroids[i].Draw(m_window);
		}
	}
	//draw bullets
	for (int i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i].isAlive())
		{
			m_bullets[i].Draw(m_window);
		}
	}
}

void Level::BulletSound()
{
}

void Level::AsteroidSound(int index)
{
	asteroids_sound.setBuffer(m_assets.GetBuffer("explosion" + std::to_string(m_asteroids[index].GetLevel())));

	asteroids_sound.play();
	
	//m_assets.SetBuffer("explosions", explosions_path[m_asteroids[index].GetLevel()]);
	//asteroids_sound.setBuffer(m_assets.GetBuffer("explosions"));
	//asteroids_sound.play();
}

void Level::AsteroidTexture()
{
	int choice = rand() % 3;
	switch (choice)
	{
	case 0:
		m_asteroid.asteroid.setTexture(m_assets.GetTexture("Asteroid0"), true);
		break;

	case 1:
		m_asteroid.asteroid.setTexture(m_assets.GetTexture("Asteroid1"), true);
		break;

	case 2:
		m_asteroid.asteroid.setTexture(m_assets.GetTexture("Asteroid2"), true);
		break;

	default:
		break;
	}
}