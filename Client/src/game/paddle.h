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

    const float velocity = 300.f;
    const float yVelocityMultiplier = 4.28f;

    unsigned int maxY;

public:
    const sf::Vector2f size = sf::Vector2f(15.f, 100.f);

// Methods
private:
    void init(sf::Vector2u windowSize);

public:
    Paddle(PaddleSide side, sf::Vector2u windowSize);
    void render(sf::RenderWindow& window);
    void move(Direction direction, sf::Time deltaTime);
    sf::Vector2f getPaddleEdge();
};