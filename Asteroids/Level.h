#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "Player.h"
#include "bullet.h"
#include "Asteroid.h"
#include "AssetMan.h"

enum AssetID
{
    PLAYER,
    ASTEROID0,
    ASTEROID1,
    ASTEROID2,

};



class Level
{
    static const float timeBetweenShots;

public:
    Level();
    ~Level();
    void Init(sf::Vector2u size);
    void onEvent(const sf::Event &event);
    void update(float deltaTime, sf::Vector2u size);
    void Draw(sf::RenderWindow &m_window);

private:
    void BulletSound();
    void AsteroidSound(int index);
    void AsteroidTexture();

    Player m_player;
    Bullet m_bullet;
    Asteroid m_asteroid;
    AssetMan m_assets;


    sf::Texture texture0, texture1, texture2;
    std::vector<sf::Sprite> asteroids_test;
    sf::Sprite asteroid_test;
    sf::Texture asteroid_texture;

    sf::SoundBuffer explosion_sfx;
    sf::Sound bullet_sound, asteroids_sound;

    std::vector<Asteroid> m_asteroids;
    std::vector<Bullet> m_bullets;


    float timer;

    bool canFire = false;

    //GUI
    int score;
    sf::Text score_text;
};


