#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H
#include "Ball.h"
#include "Paddle.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

static constexpr sf::Vector2u WINDOW_SIZE {1920, 1080};

class Game {

public:
    /**
     * Attributes
     */
    sf::RenderWindow window {sf::VideoMode( { WINDOW_SIZE } ), "PONG" };
    /** Game Objects */
    Paddle paddle_player_1 {sf::Vector2f(WINDOW_SIZE), Paddle::Player::PLAYER_1};
    Paddle paddle_player_2 {sf::Vector2f(WINDOW_SIZE), Paddle::Player::PLAYER_2};
    Ball ball { sf::Vector2f(WINDOW_SIZE) };

    /**
     * Constructor
     */
    Game();

    /**
     * Methods
     */
    void game_loop();
    void check_player_input();
    void check_ball_collision();


};


#endif //CMAKESFMLPROJECT_GAME_H