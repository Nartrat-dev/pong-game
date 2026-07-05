#ifndef CMAKESFMLPROJECT_PADDLE_H
#define CMAKESFMLPROJECT_PADDLE_H
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"


class Paddle {

public:

    enum class Player { PLAYER_1, PLAYER_2 };

    /**
     * Constructor
     */
    Paddle(sf::Vector2f window_size,  Player player);

    /**
     * Getter
     */
    sf::Vector2f get_position() const;
    sf::Vector2f get_size() const;
    sf::Color get_color() const;
    Player get_player() const;


private:
    /**
     * Attributes
     */
    sf::Vector2f position {0, 0};
    const sf::Vector2f size {10, 100};
    sf::Color color {sf::Color::White};
    Player player;




};


#endif //CMAKESFMLPROJECT_PADDLE_H