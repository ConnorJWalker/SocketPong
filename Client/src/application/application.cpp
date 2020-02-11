#include "application.h"

Application::Application() : 
    window(sf::VideoMode(720, 480), "Pong", sf::Style::Close),
    leftPaddle(PaddleSide::Left, window.getSize()),
    rightPaddle(PaddleSide::Right, window.getSize()),
    ui(&leftScore, &rightScore, window.getSize()) {}

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
            switch (key)
            {
            case sf::Keyboard::Key::Escape:
                window.close();
                break;
            }
        }

        // Handle user input, must be seperate if statements to allow more than
        // one action to be processed at a time
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            leftPaddle.move(Direction::Up);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            leftPaddle.move(Direction::Down);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            rightPaddle.move(Direction::Up);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            rightPaddle.move(Direction::Down);
        }
    }
}

void Application::render() {
    window.clear();
    
    leftPaddle.render(window);
    rightPaddle.render(window);
    ui.render(window);

    window.display();
}