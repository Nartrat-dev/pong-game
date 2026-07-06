#include "Paddle.h"

Paddle::Paddle(const sf::Vector2f &window_size, const Player &player) : player{player} {
    if (player == Player::PLAYER_1) {
        position.x = 10.0F; // Position on left side
        color = sf::Color::Blue;
    }
    if (player == Player::PLAYER_2) {
        position.x = window_size.x - 20.0F; // Position on right side
        color = sf::Color::Green;
    }
    position.y = (window_size.y / 2) - (paddle_shape.getSize().y / 2); // y Starting position: vertical center

    paddle_shape.setPosition(position);
    paddle_shape.setFillColor(color);
};

sf::Vector2f Paddle::get_position() const {
    return position;
}

sf::RectangleShape Paddle::get_shape() const {
    return paddle_shape;
}

sf::Color Paddle::get_color() const {
    return color;
}

Paddle::Player Paddle::get_player() const {
    return player;
}


void Paddle::move_up() {
    position.y -= 15.0F;
}

void Paddle::move_down() {
    position.y += 15.0F;
}

void Paddle::update_position() {
    paddle_shape.setPosition(position);
}
