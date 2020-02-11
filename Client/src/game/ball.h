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

    ScoringSide lastScore = ScoringSide::None;

// Methods
private:
    void checkAndUpdateDirection(Paddle leftPaddle, Paddle rightPaddle);
    void calculateYVelocity(Paddle paddle);

    void init();

public:
    Ball(sf::Vector2u windowSize);
    void render(sf::RenderWindow& window);
    void move(sf::Time deltaTime, Paddle leftPaddle, Paddle rightPaddle);
    ScoringSide hasScored();
};