#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Camera.hpp"

using namespace sf;

void cameraFunction(Camera* camera, const float deltaTime) {
    camera->setPosition(spaceship->getPosition());
}

Game::Game() {
    score = 0;
    fuel = FUEL_START_VALUE;
    lives = LIVES_START_VALUE;

    Spaceship* spaceship = new Spaceship();

    Scene* testScene = new Scene(&cameraFunction);
}

void Game::update(const float deltaTime) {
    
}
