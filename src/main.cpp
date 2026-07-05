#include <SFML/Graphics.hpp>

#include "Paddle.h"

int main() {

	constexpr sf::Vector2u WINDOW_SIZE {1920, 1080};

	sf::RenderWindow window( sf::VideoMode( { WINDOW_SIZE } ), "SFML works!" );


	const Paddle paddle_player_1 {sf::Vector2f(WINDOW_SIZE), Paddle::Player::PLAYER_1};
	const Paddle paddle_player_2 {sf::Vector2f(WINDOW_SIZE), Paddle::Player::PLAYER_2};

	sf::RectangleShape rect1 {paddle_player_1.get_size()};
	rect1.setPosition(paddle_player_1.get_position());
	rect1.setFillColor(paddle_player_1.get_color());

	sf::RectangleShape rect2 {paddle_player_2.get_size()};
	rect2.setPosition(paddle_player_2.get_position());
	rect2.setFillColor(paddle_player_2.get_color());

	// Start Game Loop
	while ( window.isOpen() ) {

		// Process events
		while ( const std::optional event = window.pollEvent() ) {

			// Close window: exit
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		// Clear Screen
		window.clear();

		// Draw
		window.draw(rect1);
		window.draw(rect2);

		// Update the window
		window.display();
	}
}
