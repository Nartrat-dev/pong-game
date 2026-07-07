#include "Game.h"

#include <iostream>

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

        if (playing) {
            // Check inputs
            check_player_input();

            // Check collisions
            check_paddle_collision(paddle_player_1);
            check_paddle_collision(paddle_player_2);
            check_wall_collision();

            // Update Positions
            paddle_player_1.update_position();
            paddle_player_2.update_position();
            ball.update_position();

            // Clear Screen
            window.clear();

            // Draw
            draw();
        } else if (is_won) {
            window.clear();
            window.draw(winning_text);

        }


        // Update the window
        window.display();
    }
}

void Game::draw() {
    paddle_player_1.draw_paddle(window);
    paddle_player_2.draw_paddle(window);
    paddle_player_1.get_score().draw_score(window);
    paddle_player_2.get_score().draw_score(window);
    ball.draw_ball(window);
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

    // left border collision -> point for player 2 (right player)
    if (bounds.position.x < 0.F) {
        ball.reset_position(win_size);
        paddle_player_2.get_score().score_plus_one();
        check_player_win(); // check if point leads to win
    }
    // right border collision -> point for player 1 (left player)
    if (bounds.position.x + ball.get_shape().getSize().x > win_size.x) {
        ball.reset_position(win_size);
        paddle_player_1.get_score().score_plus_one();
        check_player_win(); // check if point leads to win
    }

    // upper and lower border collision
    if (bounds.position.y < 0.F || bounds.position.y > win_size.y - ball.get_shape().getSize().y) {
        ball.revert_y_velocity();
    }
}

// Checks collision with a player paddle and reverts direction on hit
void Game::check_paddle_collision(const Paddle &paddle) {
    const auto &ball_bounds{ball.get_shape().getGlobalBounds()};
    const auto &paddle_bounds{paddle.get_shape().getGlobalBounds()};

    if (ball_bounds.findIntersection(paddle_bounds)) {
        ball.revert_x_velocity();
        const float y_velocity_new{BALL_SPEED * get_y_velocity_change_factor(paddle)};
        ball.change_y_velocity(y_velocity_new);
    }
}

// Check if one player won
void Game::check_player_win() {
    if (paddle_player_1.get_score().score_number() >= 10U) {
        winning_text.setString("Player 1 wins!");
        winning_text.setFillColor(sf::Color::White);
        winning_text.setPosition(sf::Vector2f(win_size / 2.0F));
        playing = false;
        is_won = true;
    }
    if (paddle_player_2.get_score().score_number() >= 10U) {
        winning_text.setString("Player 2 wins!");
        winning_text.setFillColor(sf::Color::White);
        winning_text.setPosition(sf::Vector2f(win_size / 2.0F));
        playing = false;
        is_won = true;
    }
}

/**
 * Gets the factor to change the amount of velocity, dependent on the position it collides on the paddle.
 * This is calculated by looking at the height (Y-Position) of both the ball and the paddle.
 * Half the length of the ball and the paddle rect are considered into the calculation to make sure
 * that the factor is dependent on the exact center of the paddle.
 * Lastly, the factor is normalized by dividing by the half-length of the paddle.
 *
 * factor can take the following values:
 * -> Collision with high position of the paddle: factor is big and positive (~0.1 to 1)
 * -> Collision with low position of the paddle: factor is big and negative  (~0.1 to -1)
 * -> Collision with middle position of the paddle: factor is (near) zero  (0)
 *
 *
 */
float Game::get_y_velocity_change_factor(const Paddle &paddle) const {
    const float ball_y{ball.get_shape().getPosition().y}; // position of ball y
    const float paddle_y{paddle.get_shape().getPosition().y}; // position of paddle y
    const float paddle_length_half{paddle.get_shape().getSize().y / 2.0F}; // half-length of paddle
    const float ball_length_half{ball.get_shape().getSize().y / 2.0F}; // half-length of ball

    const float factor{((ball_y + ball_length_half) - paddle_y - paddle_length_half) / paddle_length_half};

    return factor;
}
