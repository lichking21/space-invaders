#include "Bullet.h"

void Bullet::shoot(sf::RenderWindow& win, const sf::Vector2f& playerPos) {

	float delay = clock.getElapsedTime().asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

		// Player can shoot only once a second
		if (delay >= 1.f) {

			// Create bullet
			bullet.setSize(sf::Vector2f(5.f, 15.f));
			bullet.setFillColor(sf::Color::White);
			bullet.setPosition(playerPos.x + 35, playerPos.y);

			isFired = true;

			clock.restart();
		}
	}

	if (isFired) {

		// Move bullet
		bullet.move(0, -bulletSpeed);
		win.draw(bullet); 

		if (bullet.getPosition().y < 0)
			isFired = false;
	}
}
