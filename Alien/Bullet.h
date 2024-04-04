#ifndef BULLET_H
#define BULLET_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// Players bullet
class Bullet {

public:

	sf::RectangleShape bullet;
	sf::Clock clock;

	bool isFired = false;
	float bulletSpeed = 0.5f;

	void shoot(sf::RenderWindow& win, const sf::Vector2f& playerPos);
};


#endif // !BULLET_H
