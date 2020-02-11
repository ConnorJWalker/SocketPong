#pragma once
#include <SFML/Graphics.hpp>

class UI {
// Properties
private:
    int* leftScore = nullptr;
    int* rightScore = nullptr;
    float* fps = nullptr;

    sf::Font font;

    sf::Text leftScoreLable;
    sf::Text rightScoreLable;
    sf::Text fpsLable;

// Methods
private:
    void init(sf::Vector2u windowSize);

public:
    UI(int* leftScore, int* rightScore, float* fps, sf::Vector2u windowSize);
    void render(sf::RenderWindow& window, bool showFps);
};