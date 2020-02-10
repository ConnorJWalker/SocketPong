#pragma once
#include <SFML/Graphics.hpp>

enum class Direction {
    Up = -1, Down = 1
};

enum class PaddleSide {
    Left, Right
};

class Paddle {
// Properties
private:
    PaddleSide side;
    sf::RectangleShape body;

    const float speed = 3.f;

// Methods
private:
    void init(sf::Vector2u windowSize);

public:
    Paddle(PaddleSide side, sf::Vector2u windowSize);
    void render(sf::RenderWindow& window);
    void move(Direction direction);
};