#include "application.h"

Application::Application() : window(sf::VideoMode(720, 480), "Pong", sf::Style::Close),
    leftPaddle(PaddleSide::Left, window.getSize()),
    rightPaddle(PaddleSide::Right, window.getSize()) {}

void Application::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
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

void Application::render() {
    window.clear();
    
    leftPaddle.render(window);
    rightPaddle.render(window);

    window.display();
}