#include <SFML/Graphics.hpp>

#include "Ball.h"
#include "Paddle.h"

int main() {

	/** Window */
	constexpr sf::Vector2u WINDOW_SIZE {1920, 1080};
	sf::RenderWindow window( sf::VideoMode( { WINDOW_SIZE } ), "PONG" );
	window.setFramerateLimit(60);

	/** Game Objects */
	Paddle paddle_player_1 {sf::Vector2f(WINDOW_SIZE), Paddle::Player::PLAYER_1};
	Paddle paddle_player_2 {sf::Vector2f(WINDOW_SIZE), Paddle::Player::PLAYER_2};
	Ball ball { sf::Vector2f(WINDOW_SIZE) };

	// Start Game Loop
	while ( window.isOpen() ) {

		// Process events
		while ( const std::optional event = window.pollEvent() ) {

			// Close window: exit
			if ( event->is<sf::Event::Closed>() ) { window.close(); }
		}

		/** On Key pressed */
		// Player 1 movement
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ) { paddle_player_1.move_up(); }
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ) { paddle_player_1.move_down(); }

		// Player 2 movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ) { paddle_player_2.move_up(); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ) { paddle_player_2.move_down(); }

		// Clear Screen
		window.clear();

		// Update Positions
		paddle_player_1.update_position();
		paddle_player_2.update_position();
		ball.update_position();

		// Draw
		window.draw(paddle_player_1.get_shape());
		window.draw(paddle_player_2.get_shape());
		window.draw(ball.get_shape());

		// Update the window
		window.display();
	}
}
