#pragma once
#include "../game/paddle.h"
#include <SFML/Graphics.hpp>

class Application {
// Properties
private:
    sf::RenderWindow window;
    Paddle leftPaddle;
    Paddle rightPaddle;

// Methods
private:
    void handleEvents();
    void render();

public:
    Application();
    void run();
};
