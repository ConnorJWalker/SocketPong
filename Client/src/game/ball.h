#pragma once
#include "paddle.h"
#include <SFML/Graphics.hpp>

enum class ScoringSide {
    Left, Right, None
};

class Ball {
// Properties
private:
    const int radius = 7;

    sf::CircleShape body;
    sf::Vector2u windowSize;

    sf::Vector2f velocity = sf::Vector2f(-300.f, 0.f);

// Methods
private:
    void checkAndUpdateDirection(Paddle leftPaddle, Paddle rightPaddle);

public:
    Ball(sf::Vector2u windowSize);
    void render(sf::RenderWindow& window);
    void move(sf::Time deltaTime, Paddle leftPaddle, Paddle rightPaddle);
    ScoringSide hasScored();
};