#ifndef CMAKESFMLPROJECT_PADDLE_H
#define CMAKESFMLPROJECT_PADDLE_H
#include "config.h"
#include "Score.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


class Paddle {
public:
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

    Score get_score() const;

    /**
     * Methods
     */
    void move_up();

    void move_down();

    void update_position();

    void draw_paddle(sf::RenderWindow &window) const;

private:
    /**
     * Attributes
     */
    sf::RectangleShape paddle_shape{sf::Vector2f{10.0F, 100.0F}};
    sf::Vector2f position{0, 0};
    sf::Color color{sf::Color::White};
    Player player;
    Score score;
};


#endif //CMAKESFMLPROJECT_PADDLE_H
