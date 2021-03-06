#include "application.h"

Application::Application() : 
    window(sf::VideoMode(720, 480), "Pong", sf::Style::Close),
    leftPaddle(PaddleSide::Left, window.getSize()),
    rightPaddle(PaddleSide::Right, window.getSize()),
    ui(&leftScore, &rightScore, &fps, window.getSize()),
    ball(window.getSize()) {}

void Application::run() {
    while (window.isOpen()) {
        deltaTime = deltaClock.restart();
        
        handleEvents();

        ball.move(deltaTime, leftPaddle, rightPaddle);
        ScoringSide currentScorer = ball.hasScored();
        if (currentScorer != ScoringSide::None) {
            if (currentScorer == ScoringSide::Left)
                leftScore++;
            else
                rightScore++;
        }

        render();

        fps = 1.f / deltaTime.asSeconds();
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
            case sf::Keyboard::Key::Space:
                showFramerate = !showFramerate;
                break;
            }
        }
    }


    // Handle user input, must be seperate if statements to allow more than
    // one action to be processed at a time
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        leftPaddle.move(Direction::Up, deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        leftPaddle.move(Direction::Down, deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        rightPaddle.move(Direction::Up, deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        rightPaddle.move(Direction::Down, deltaTime);
    }
}

void Application::render() {
    window.clear();
    
    leftPaddle.render(window);
    rightPaddle.render(window);
    ui.render(window, showFramerate);
    ball.render(window);

    window.display();
}