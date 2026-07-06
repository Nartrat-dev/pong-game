#ifndef CMAKESFMLPROJECT_PADDLE_H
#define CMAKESFMLPROJECT_PADDLE_H
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"


class Paddle {
public:
    enum class Player { PLAYER_1, PLAYER_2 };

    /**
     * Constructor
     */
    Paddle(const sf::Vector2f &window_size, const Player &player);

    /**
     * Getter
     */
    sf::Vector2f get_position() const;

    sf::RectangleShape get_shape() const;

    sf::Color get_color() const;

    Player get_player() const;

    /**
     * Methods
     */
    void move_up();

    void move_down();

    void update_position();

private:
    /**
     * Attributes
     */
    sf::RectangleShape paddle_shape{sf::Vector2f{10.0F, 100.0F}};
    sf::Vector2f position{0, 0};
    sf::Color color{sf::Color::White};
    Player player;
};


#endif //CMAKESFMLPROJECT_PADDLE_H
