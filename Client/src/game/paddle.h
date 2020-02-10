#pragma once
#include <SFML/Graphics.hpp>

enum class Direction {
    Up, Down
};

enum class PaddleSide {
    Left, Right
};

class Paddle {
// Properties
private:
    PaddleSide side;
    sf::RectangleShape body;

// Methods
private:
    void init(sf::Vector2u windowSize);

public:
    Paddle(PaddleSide side, sf::Vector2u windowSize);
    void render(sf::RenderWindow& window);
};