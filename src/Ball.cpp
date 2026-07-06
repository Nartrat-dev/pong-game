#include "Ball.h"

#include "config.h"

Ball::Ball(const sf::Vector2f &window_size) : position{window_size / 2.0F} {
    circle_shape.setFillColor(color);
    circle_shape.setPosition(position);
}

void Ball::move() {
    position += velocity;
}

void Ball::update_position() {
    move();
    circle_shape.setPosition(position);
}

void Ball::revert_x_velocity() {
    velocity.x *= -1.0F;
}

void Ball::revert_y_velocity() {
    velocity.y *= -1.0F;
}

void Ball::reset_position() {
    position = sf::Vector2f(WINDOW_SIZE) / 2.0F;
}


sf::Vector2f Ball::get_velocity() const { return velocity; }
sf::Vector2f Ball::get_position() const { return position; };
sf::CircleShape Ball::get_shape() const { return circle_shape; }
