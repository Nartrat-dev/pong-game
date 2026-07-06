#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H
#include "Ball.h"
#include "config.h"
#include "Paddle.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

/**
 * Includes the logic of the game and brings the classes together
 */
class Game {
public:
    /**
     * Attributes
     */
    // Window
    sf::RenderWindow window{sf::VideoMode({WINDOW_SIZE}), "PONG"};

    // Game Objects
    Paddle paddle_player_1{sf::Vector2f(WINDOW_SIZE), Paddle::Player::PLAYER_1};
    Paddle paddle_player_2{sf::Vector2f(WINDOW_SIZE), Paddle::Player::PLAYER_2};
    Ball ball{sf::Vector2f(WINDOW_SIZE)};

    /**
     * Constructor
     */
    Game();

    /**
     * Methods
     */
    // Game Loop
    void game_loop();

    // Checks player inputs and moves paddles depending on input
    void check_player_input();

    // Checks for wall collision and executes corresponding logic
    void check_wall_collision();

    // Checks collision with a player paddle and reverts direction on hit
    void check_paddle_collision(const Paddle &paddle);

    // Get a factor for the velocity update of y for the ball when hitting the paddle,
    // depending on position of the paddle
    float get_y_velocity_change_factor(const Paddle &paddle) const;
};


#endif //CMAKESFMLPROJECT_GAME_H
