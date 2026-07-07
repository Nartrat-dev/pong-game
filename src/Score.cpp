#include "Score.h"

Score::Score(const Player &player, const sf::Vector2f &window_size) {
    score_position.y = window_size.y - 30.0F; // always same height for score

    // different x position depending on player
    if (player == Player::PLAYER_1) {
        score_position.x = window_size.x / 2.0F - 30.0F;
    }
    if (player == Player::PLAYER_2) {
        score_position.x = window_size.x / 2.0F + 30.0F;
    }

    score_display.setPosition(score_position);
    score_display.setFillColor(sf::Color::White);
    score_display.setString(std::to_string(score));
    score_display.setCharacterSize(24);
}

// Add +1 to score and update the display of the score
void Score::score_plus_one() {
    score++;
    score_display.setString(std::to_string(score));
}

void Score::draw_score(sf::RenderWindow &window) const {
    window.draw(score_display);
}

unsigned& Score::score_number() {
    return score;
}