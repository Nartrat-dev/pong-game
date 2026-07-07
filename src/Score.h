#ifndef CMAKESFMLPROJECT_SCORE_H
#define CMAKESFMLPROJECT_SCORE_H

#include "config.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"

/**
 * Class to handle the logic for counting up and displaying the score of each player / paddle
 */
class Score {

    unsigned int score{0};
    sf::Font font{"../resources/Arial.ttf"};
    sf::Text score_display{sf::Text(font)};
    sf::Vector2f score_position;

public:

    explicit Score(const Player &player, const sf::Vector2f &window_size);

    // Add +1 to score and update the display of the score
    void score_plus_one();

    void draw_score(sf::RenderWindow &window) const;
};


#endif //CMAKESFMLPROJECT_SCORE_H
