#include "Game.h"

Game::Game() {
    window.setFramerateLimit(60);
}

void Game::game_loop() {

    // Start game loop
    while ( window.isOpen() ) {

        // Process events
        while ( const std::optional event = window.pollEvent() ) {

            // Close window: exit
            if ( event->is<sf::Event::Closed>() ) { window.close(); }
        }

        // Check inputs
        check_player_input();

        // Check collisions
        check_ball_collision();

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

void Game::check_player_input() {
    // Player 1 movement
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ) { paddle_player_1.move_up(); }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ) { paddle_player_1.move_down(); }

    // Player 2 movement
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ) { paddle_player_2.move_up(); }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ) { paddle_player_2.move_down(); }
}

void Game::check_ball_collision() {
    const auto &bounds { ball.get_shape().getGlobalBounds() };
    const auto &window_size { window.getSize() };

    // left and right border collision
    if (bounds.position.x < 0.F || bounds.position.x > window_size.x) { ball.change_x_direction(); }

    // upper and lower border collision
    if (bounds.position.y < 0.F || bounds.position.y > window_size.y) { ball.change_y_direction(); }
}