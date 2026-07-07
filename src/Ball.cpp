#include "Ball.h"

#include "config.h"

Ball::Ball(const sf::Vector2f &window_size) : position{window_size / 2.0F} {
    ball_shape.setFillColor(color);
    ball_shape.setPosition(position);
}

void Ball::move() {
    position += velocity;
}

void Ball::update_position() {
    move();
    ball_shape.setPosition(position);
}

void Ball::revert_x_velocity() {
    velocity.x *= -1.0F;
}

void Ball::revert_y_velocity() {
    velocity.y *= -1.0F;
}

void Ball::reset_position(const sf::Vector2f &window_size, const Player &player_direction) {
    float direction{1.0F};

    // Change direction to the left (to player 1)
    if (player_direction == Player::PLAYER_1) {
        direction = -1.0F;
    }

    position = sf::Vector2f(window_size) / 2.0F;
    velocity = sf::Vector2f(direction * BALL_SPEED, 0.0F);
}

void Ball::change_y_velocity(const float &value) {
    velocity.y = value;
}

void Ball::draw_ball(sf::RenderWindow &window) const {
    window.draw(ball_shape);
}

sf::Vector2f Ball::get_velocity() const { return velocity; }
sf::Vector2f Ball::get_position() const { return position; };
sf::RectangleShape Ball::get_shape() const { return ball_shape; }
