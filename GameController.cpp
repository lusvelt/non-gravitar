#include <SFML/Graphics.hpp>

#include "GameController.hpp"

using namespace sf;

Clock GameController::clock;
Time GameController::deltaTime;

GameController::GameController(RenderWindow& w) {
    score = 0;
    fuel = FUEL_START_VALUE;
    lives = LIVES_START_VALUE;
    spaceship = Spaceship();
    window = &w;
    clock.restart();
}

void GameController::setDeltaTime() {
    deltaTime = clock.getElapsedTime();
    clock.restart();
}

void GameController::run() {
    window->clear(Color::Black);
    window->draw(spaceship.getShape());
    window->display();
    setDeltaTime();
    spaceship.update();
}

Time GameController::getDeltaTime() {
    return deltaTime;
}
