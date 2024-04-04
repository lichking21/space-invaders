#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

const float WINDOW_WIDTH = 800.f;
const float WINDOW_HEIGHT = 600.f;

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders");
	int attackCount = 3;

	Player player;
	Bullet bullet;
	Alien alien(0.f, 0.f);

	alien.draw();
	player.draw();
	
	while (true) {

		while (window.isOpen()) {

			sf::Event event;

			while (window.pollEvent(event)) {

				if (event.type == sf::Event::Closed) window.close();
			}

			window.clear();
			

			// Aliens crowd controll
			for (auto& row : alien.enemyes) {

				for (auto& enemy : row) {

					alien.move();
					window.draw(enemy);
				}
			}

			player.move();
			player.takeDamage(alien);

			bullet.shoot(window, player.shape.getPosition());

			alien.takeDamage(bullet);
			for (int i = 0; i < attackCount; i++) alien.attack(window);

			window.draw(player.shape);
			window.display();

			// Restart game
			if (player.health <= 0) {

				char ch;
				std::cout << "Start again?\t [ y/N ]\n";
				std::cin >> ch;
				std::cout << endl;

				if (ch == 'y') {

					player.health = 3;
					alien.enemyes.clear();
					alien.draw();
				}
				if (ch == 'N') return 0;
			}
		}
	}
}