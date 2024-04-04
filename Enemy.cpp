#include "Enemy.h"

void Alien::draw() {

	// Position of spawn
	float x = 10.f;
	float y = -50.f;

	int rows = 3;
	int columns = 15;

	// Fill 2D vector with aliens
	for (size_t i = 0; i < rows; i++) {

		vector<sf::Sprite> row;
		for (size_t j = 0; j < columns; j++) {

			setSprite(x, y);
			row.push_back(sprite);
			x += 50.f;
		}
		enemyes.push_back(row);
		y += 30.f;
		x = 10.f;
	}
}

void Alien::move() {

	// Itterate 2D vector of alliens
	for (auto& row : enemyes) {

		bool moveDown = false;

		for (auto& enemy : row) {

			// Get position of current alien
			sf::Vector2f spritePos = enemy.getPosition();

			// Check if allien hits the left border
			if (spritePos.x < 0) {

				// Push alien to the right
				spritePos.x = 0;
				velocity.x = abs(velocity.x);
				moveDown = true;
			}

			// Check if alien hits the right border
			if (spritePos.x > 730.f + sprite.getGlobalBounds().width) {

				// Push alien to the left
				spritePos.x = 730.f + sprite.getGlobalBounds().width;
				velocity.x = -abs(velocity.x);
				moveDown = true;
			}

			// Move aliens
			spritePos.x += velocity.x;
			spritePos.y += velocity.y;

			enemy.setPosition(spritePos);

		}

		// When aliens hit borders, move them down
		if (moveDown) {

			for (auto& enemy : row) {

				sf::Vector2f spritePos = enemy.getPosition();
				spritePos.y += 10.f;
				enemy.setPosition(spritePos);
			}
		}
	}
}

void Alien::takeDamage(Bullet& bullet) {

	sf::FloatRect bulletBounds = bullet.bullet.getGlobalBounds();
	
	for (auto row = enemyes.begin(); row != enemyes.end(); ++row) {

		for (auto it = row->begin(); it != row->end(); ++it) {
			
			// Kill current hited alien
			if (bulletBounds.intersects(it->getGlobalBounds()) && bullet.isFired) {

				row->erase(it);

				bullet.isFired = false;	

				// With every killed alien, increase movement speed
				speedX += 0.00001f;
				velocity = sf::Vector2f(speedX, speedY);

				break;
			}
		}
	}
}

void Alien::attack(sf::RenderWindow& window) {

	float delay = 2.f;

	// Create bullet every 2 seconds
	if (!hit && clock.getElapsedTime().asSeconds() >= delay) {

		// Choose random alien
		// 
		// Random row with index i
		int i = std::rand() % enemyes.size();
		vector<sf::Sprite>& row = enemyes[i];

		// Get position of random alien with index j
		int j = std::rand() % row.size();
		sf::Vector2f alienPos = row[j].getPosition();

		// Create bullet
		bullet.setSize(sf::Vector2f(5.f, 15.f));
		bullet.setFillColor(sf::Color::Cyan);
		bullet.setPosition(alienPos.x, alienPos.y);

		hit = true;
	}

	// Shoot bullet every 2 seconds
	if (hit) {

		bullet.move(0, bulletSpeed);
		window.draw(bullet);

		if (bullet.getPosition().y > 600.f) hit = false;
	}
}