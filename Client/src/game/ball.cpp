#include "ball.h"

Ball::Ball(sf::Vector2u windowSize) {
    this->windowSize = windowSize;
    body.setRadius(7);
    body.setPosition(windowSize.x / 2, windowSize.y / 2);
}

void Ball::move(sf::Time deltaTime) {
    body.move(velocity * deltaTime.asSeconds());
}

void Ball::render(sf::RenderWindow& window) {
    window.draw(body);
}