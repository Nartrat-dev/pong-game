#include "Ball.h"

Ball::Ball(const sf::Vector2f& window_size) : position{ window_size / 2.0F } {
    circle_shape.setFillColor(color);
    circle_shape.setPosition(position);
}

void Ball::move() {
    position += velocity;
}

void Ball::update_position() {
    circle_shape.setPosition(position);
}

sf::Vector2f Ball::get_velocity() const { return velocity; }
sf::Vector2f Ball::get_position() const { return position; };
sf::CircleShape Ball::get_shape() const { return circle_shape; }