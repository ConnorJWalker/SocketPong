#include "paddle.h"

Paddle::Paddle(PaddleSide side, sf::Vector2u windowSize) {
    this->side = side;
    maxY = windowSize.y;

    init(windowSize);
}

void Paddle::init(sf::Vector2u windowSize) {
    body.setSize(size);
    body.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));

    float xPosition = side == PaddleSide::Left? 25 :  windowSize.x - 25;
    float yPosition = windowSize.y / 2;
    body.setPosition(sf::Vector2f(xPosition, yPosition));
}

void Paddle::render(sf::RenderWindow& window) {
    window.draw(body);
}

void Paddle::move(Direction direction, sf::Time deltaTime) {
    sf::Vector2f position = body.getPosition();
    if (direction == Direction::Up && position.y - size.y / 2 > 0) {
        body.move(0.f, (float)direction * velocity * deltaTime.asSeconds());
    } 
    else if (direction == Direction::Down && position.y + size.y / 2 < maxY) {
        body.move(0.f, (float)direction * velocity * deltaTime.asSeconds());
    }
}