#include "Game.h"

// Makes an instant of the game, sets frame limit
Game::Game() {
    window.setFramerateLimit(FPS);
}

// Main loop of the game
void Game::game_loop() {
    // Start game loop
    while (window.isOpen()) {
        // Process events
        while (const std::optional event = window.pollEvent()) {
            // Close window: exit
            if (event->is<sf::Event::Closed>()) { window.close(); }
        }

        // Check inputs
        check_player_input();

        // Check collisions
        check_wall_collision();
        check_paddle_collision();

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

// Checks player inputs and moves paddles depending on input
void Game::check_player_input() {
    // Player 1 movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) { paddle_player_1.move_up(); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) { paddle_player_1.move_down(); }

    // Player 2 movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) { paddle_player_2.move_up(); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) { paddle_player_2.move_down(); }
}

// Checks for wall collision and executes corresponding logic
void Game::check_wall_collision() {
    const auto &bounds{ball.get_shape().getGlobalBounds()};
    const auto &window_size{window.getSize()};

    // left and right border collision
    if (bounds.position.x < 0.F || bounds.position.x + ball.get_shape().getRadius() * 2 > window_size.x) {
        ball.reset_position();
    }

    // upper and lower border collision
    if (bounds.position.y < 0.F || bounds.position.y > window_size.y - ball.get_shape().getRadius() * 2) {
        ball.revert_y_velocity();
    }
}

// Checks collision with a player paddle and reverts direction on hit
void Game::check_paddle_collision() {
    const auto &ball_bounds{ball.get_shape().getGlobalBounds()};
    const auto &player1_bounds{paddle_player_1.get_shape().getGlobalBounds()};
    const auto &player2_bounds{paddle_player_2.get_shape().getGlobalBounds()};

    if (ball_bounds.findIntersection(player1_bounds)) { ball.revert_x_velocity(); }
    if (ball_bounds.findIntersection(player2_bounds)) { ball.revert_x_velocity(); }
}
