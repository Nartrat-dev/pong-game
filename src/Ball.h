#ifndef CMAKESFMLPROJECT_BALL_H
#define CMAKESFMLPROJECT_BALL_H
#include "config.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


class Ball {
public:
    /**
     * Constructor
     */
    explicit Ball(const sf::Vector2f &window_size);

    /**
     * Methods
     */
    void move();

    void update_position();

    void revert_x_velocity();

    void revert_y_velocity();

    void reset_position(const sf::Vector2f &window_size, const Player &player_direction);

    void change_y_velocity(const float &value);

    void draw_ball(sf::RenderWindow &window) const;

    /**
     * Getter
     */
    sf::Vector2f get_velocity() const;

    sf::Vector2f get_position() const;

    sf::RectangleShape get_shape() const;

private:
    /**
     * Attributes
     */
    sf::Vector2f velocity{BALL_SPEED, 0.0F}; // initialize with horizontal movement
    sf::Vector2f position{0.0F, 0.0F};
    sf::RectangleShape ball_shape{sf::Vector2f{20.0F, 20.0F}};
    sf::Color color{sf::Color::White};
};


#endif //CMAKESFMLPROJECT_BALL_H
