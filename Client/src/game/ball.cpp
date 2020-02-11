#include "ball.h"

Ball::Ball(sf::Vector2u windowSize) {
    this->windowSize = windowSize;
    init();
}

void Ball::init() {
    body.setRadius(radius);
    body.setPosition(windowSize.x / 2, windowSize.y / 2);
}

void Ball::checkAndUpdateDirection(Paddle leftPaddle, Paddle rightPaddle) {
    sf::Vector2f ballPosition = body.getPosition();
    float paddleHeight = leftPaddle.size.y;

    // Check to see if the ball has hit the left paddle
    if (ballPosition.x < windowSize.x / 2) {
        sf::Vector2f paddleEdge = leftPaddle.getPaddleEdge();
        if (ballPosition.x - radius <= paddleEdge.x) {
            if (ballPosition.x < 0) {
                lastScore = ScoringSide::Right;
                init();
            }
           
            if (ballPosition.y > paddleEdge.y - paddleHeight / 2 && ballPosition.y < paddleEdge.y + paddleHeight / 2) {
                velocity.x *= -1;
            }
        }
    }

    // Check to see if the ball has hit the right paddle
    if (ballPosition.x > windowSize.x / 2) {
        sf::Vector2f paddleEdge = rightPaddle.getPaddleEdge();
        if (ballPosition.x + radius >= paddleEdge.x) {
            if (ballPosition.x > windowSize.x) {
                lastScore = ScoringSide::Left;
                init();
            }

            if (ballPosition.y > paddleEdge.y - paddleHeight / 2 && ballPosition.y < paddleEdge.y + paddleHeight / 2) { 
                velocity.x *= -1;
            }
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

ScoringSide Ball::hasScored() {
    ScoringSide returnValue = lastScore;
    lastScore = ScoringSide::None;

    return returnValue;
}