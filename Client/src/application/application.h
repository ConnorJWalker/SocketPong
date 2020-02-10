#pragma once
#include <SFML/Graphics.hpp>

class Application {
// Properties
private:
    sf::RenderWindow window;

// Methods
private:
    void handleEvents();

public:
    Application();
    void run();
};
