#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "Bullet.h"

using namespace std;

const float ALIEN_WIDTH = 40.f;
const float ALIEN_HEIGHT = 20.f;

class Alien {

public:

	sf::Vector2f velocity;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Clock clock;
	sf::RectangleShape bullet;

	vector<vector<sf::Sprite>> enemyes;
	
	bool hit = false;
	float speedX = 0.0005f;
	float speedY = 0.f;
	float bulletSpeed = 0.05f;

	
	// Constructor with parameters
	Alien(float x, float y) {

		loadTexture("../assets/alien.png");
		setSprite(x, y);
		velocity = sf::Vector2f(speedX, speedY);
	}

	void loadTexture(const std::string& filename) {

		if (!texture.loadFromFile(filename))
			std::cerr << "Failed to load texture\n";
	}
	void setSprite(float x, float y) {

		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(ALIEN_WIDTH / texture.getSize().x, ALIEN_HEIGHT / texture.getSize().y));
		sprite.setPosition(x, y);
	}

	void draw();
	void move();
	void takeDamage(Bullet& bullet);
	void attack(sf::RenderWindow& window);
};

#endif // !ENEMY+H

