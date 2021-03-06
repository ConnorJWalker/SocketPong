#include "ui.h"

UI::UI(int* leftScore, int* rightScore, float* fps, sf::Vector2u windowSize) {
    this->leftScore = leftScore;
    this->rightScore = rightScore;
    this->fps = fps;

    init(windowSize);
};

void UI::init(sf::Vector2u windowSize) {
    // TODO: handle possible exception
    font.loadFromFile("Client/assets/Roboto-Regular.ttf");
    
    leftScoreLable.setFont(font);
    leftScoreLable.setCharacterSize(24);
    leftScoreLable.setPosition(sf::Vector2f(windowSize.x / 4, 15.f));

    rightScoreLable.setFont(font);
    rightScoreLable.setCharacterSize(24);
    rightScoreLable.setPosition(sf::Vector2f(windowSize.x - windowSize.x / 4, 15.f));

    fpsLable.setFont(font);
    fpsLable.setCharacterSize(24);
    fpsLable.setPosition(sf::Vector2f(15.f, windowSize.y - 39.f));
}

void UI::render(sf::RenderWindow& window, bool showFps) {
    leftScoreLable.setString(std::to_string(*leftScore));
    window.draw(leftScoreLable);

    rightScoreLable.setString(std::to_string(*rightScore));
    window.draw(rightScoreLable);

    if (showFps) {
        fpsLable.setString(std::to_string(*fps));
        window.draw(fpsLable);
    }
}
