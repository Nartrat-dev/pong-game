#ifndef CMAKESFMLPROJECT_BALL_H
#define CMAKESFMLPROJECT_BALL_H
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"


class Ball {
public:
    /**
     * Constructor
     */
    explicit Ball(const sf::Vector2f& window_size);

    /**
     * Methods
     */
    void move();
    void update_position();
    void revert_x_velocity();
    void revert_y_velocity();
    void reset_position();

    /**
     * Getter
     */
    sf::Vector2f get_velocity() const;
    sf::Vector2f get_position() const;
    sf::CircleShape get_shape() const;


private:
    /**
     * Attributes
     */
    sf::Vector2f velocity {5.0F, 5.0F};
    sf::Vector2f position;
    sf::CircleShape circle_shape { 25.0F };
    sf::Color color {sf::Color::White};
};


#endif //CMAKESFMLPROJECT_BALL_H