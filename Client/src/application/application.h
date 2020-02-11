#pragma once
#include "ui/ui.h"
#include "../game/paddle.h"
#include <SFML/Graphics.hpp>

class Application {
// Properties
private:
    sf::RenderWindow window;
    Paddle leftPaddle;
    Paddle rightPaddle;

    UI ui;

    int leftScore = 0;
    int rightScore = 0;
// Methods
private:
    void handleEvents();
    void render();

public:
    Application();
    void run();
};
