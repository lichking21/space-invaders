#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"

class Player {

public:

	sf::RectangleShape shape;
	float speed = 0.1f;
	int health = 3;
	int score = 0;

	void draw();
	void move();
	void takeDamage(Alien& alien);
};

#endif // !PLAYER_H


