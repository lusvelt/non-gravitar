#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "Game.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include "Bunker.hpp"

using namespace sf;

const void cameraFunction(Camera* camera, const float deltaTime, vector<Object*> *sceneObjects) {
    Vector2f spaceshipPosition = sceneObjects->at(0)->getPosition();
    camera->setPosition(Vector2f(spaceshipPosition.x - WINDOW_WIDTH / 2, spaceshipPosition.y - WINDOW_HEIGHT / 2));
}

Game::Game() {
    score = 0;
    fuel = FUEL_START_VALUE;
    lives = LIVES_START_VALUE;

    Scene* testScene = new Scene(&cameraFunction);
    Engine::setCurrentScene(testScene);
    Spaceship* spaceship = new Spaceship();
    // Bunker* bunker = new Bunker();
    this->scenes.push_back(testScene);
}

void Game::update(const float deltaTime) { }
