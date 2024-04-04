#include "Player.h"

void Player::draw() {

	this->shape.setSize(sf::Vector2f(70.f, 40.f));
	this->shape.setFillColor(sf::Color::Blue);

	this->shape.setPosition(sf::Vector2f(100.f, 560.f));
}

void Player::move() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		shape.move(speed, 0.f);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		shape.move(-speed, 0.f);
}

void Player::takeDamage(Alien& alien) {

	sf::FloatRect bulletBounds = alien.bullet.getGlobalBounds();

	if (bulletBounds.intersects(shape.getGlobalBounds()) && alien.hit) {

		alien.hit = false;
		health -= 1;
	}
}