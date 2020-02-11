#include "paddle.h"

Paddle::Paddle(PaddleSide side, sf::Vector2u windowSize) : body(sf::Vector2f(15.f, 100.f)) {
    this->side = side;
    init(windowSize);
}

void Paddle::init(sf::Vector2u windowSize) {
    sf::Vector2f bodySize = body.getSize();
    body.setOrigin(sf::Vector2f(bodySize.x / 2, bodySize.y / 2));

    float xPosition = side == PaddleSide::Left? 25 :  windowSize.x - 25;
    float yPosition = windowSize.y / 2;
    body.setPosition(sf::Vector2f(xPosition, yPosition));
}

void Paddle::render(sf::RenderWindow& window) {
    window.draw(body);
}

void Paddle::move(Direction direction, sf::Time deltaTime) {
    body.move(0.f, (float)direction * velocity * deltaTime.asSeconds());
}