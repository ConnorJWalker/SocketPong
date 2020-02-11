#include "ball.h"

Ball::Ball(sf::Vector2u windowSize) {
    this->windowSize = windowSize;
    body.setRadius(radius);
    body.setPosition(windowSize.x / 2, windowSize.y / 2);
}

void Ball::checkAndUpdateDirection(Paddle leftPaddle, Paddle rightPaddle) {
    sf::Vector2f ballPosition = body.getPosition();

    // Check to see if the ball has hit the left paddle
    if (ballPosition.x < windowSize.x / 2) {
        if (ballPosition.x - radius <= leftPaddle.getPaddleEdge().x) {
            velocity.x *= -1;
        }
    }

    // Check to see if the ball has hit the right paddle
    if (ballPosition.x > windowSize.x / 2) {
        if (ballPosition.x + radius >= rightPaddle.getPaddleEdge().x) {
            velocity.x *= -1;
        }
    }
}


void Ball::move(sf::Time deltaTime, Paddle leftPaddle, Paddle rightPaddle) {
    body.move(velocity * deltaTime.asSeconds());

    checkAndUpdateDirection(leftPaddle, rightPaddle);
}

void Ball::render(sf::RenderWindow& window) {
    window.draw(body);
}