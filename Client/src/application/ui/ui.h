#pragma once
#include <SFML/Graphics.hpp>

class UI {
// Properties
private:
    int* leftScore = nullptr;
    int* rightScore = nullptr;

    sf::Font font;

    sf::Text leftScoreLable;
    sf::Text rightScoreLable;

// Methods
private:
    void init(sf::Vector2u windowSize);

public:
    UI(int* leftScore, int* rightScore, sf::Vector2u windowSize);
    void render(sf::RenderWindow& window);
};