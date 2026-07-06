#include "Paddle.h"

Paddle::Paddle(const sf::Vector2f& window_size, const Player& player) : player{player} {

    if (player == Player::PLAYER_1) {
        position.x = 10 ; // Position on left side
        color = sf::Color::Blue;
    }
    if (player == Player::PLAYER_2) {
        position.x = window_size.x - 20; // Position on right side
        color = sf::Color::Green;
    }
    position.y = (window_size.y / 2) - (rect_shape.getSize().y / 2); // y Starting position: vertical center

    rect_shape.setPosition(position);
    rect_shape.setFillColor(color);
};

sf::Vector2f Paddle::get_position() const {
    return position;
}
sf::RectangleShape Paddle::get_shape() const {
    return rect_shape;
}
sf::Color Paddle::get_color() const {
    return color;
}
Paddle::Player Paddle::get_player() const {
    return player;
}


void Paddle::move_up() {
    position.y--;
}
void Paddle::move_down() {
    position.y++;
}
void Paddle::update_position() {
    rect_shape.setPosition(position);
}