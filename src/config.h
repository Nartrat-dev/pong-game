#ifndef CMAKESFMLPROJECT_CONFIG_H
#define CMAKESFMLPROJECT_CONFIG_H
#include "SFML/Graphics/Font.hpp"
#include "SFML/System/Vector2.hpp"

// Size of the window
static constexpr sf::Vector2u WINDOW_SIZE{1920, 1080};

// Number of frames per second
static constexpr unsigned FPS{60};

// Speed of ball
static constexpr float BALL_SPEED{7.5F};

// Player
enum class Player { PLAYER_1, PLAYER_2 };

// Font
static sf::Font FONT{"./resources/Arial.ttf"};

#endif //CMAKESFMLPROJECT_CONFIG_H
