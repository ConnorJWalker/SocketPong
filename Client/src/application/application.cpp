#include "application.h"

Application::Application() : window(sf::VideoMode(720, 480), "Pong", sf::Style::Close) {}

void Application::run() {
    while (window.isOpen()) {
        handleEvents();
    }
}

void Application::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            sf::Keyboard::Key key = event.key.code;
            if (key == sf::Keyboard::Key::Escape) {
                window.close();
            }
        }
    }
}