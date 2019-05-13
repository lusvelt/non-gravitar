#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "Game.hpp"
#include "SolarSystem.hpp"
#include "Camera.hpp"
#include "Planet.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include "Bunker.hpp"
#include "TankBunker.hpp"
#include "DoubleShootBunker.hpp"
#include "CleverBunker.hpp"
#include "TwoDirectionBunker.hpp"
#include "ThreeDirectionBunker.hpp"

using namespace sf;

const void cameraFunction(Camera* camera, const float deltaTime, vector<Object*> *sceneObjects) {
    Vector2f spaceshipPosition = sceneObjects->at(0)->getPosition();
    camera->setPosition(Vector2f(spaceshipPosition.x - WINDOW_WIDTH / 2, spaceshipPosition.y - WINDOW_HEIGHT / 2));
}

Game::Game() {
    score = 0;
    fuel = FUEL_START_VALUE;
    lives = LIVES_START_VALUE;

    Scene* testScene = new SolarSystem();
    Engine::instantiate(new Spaceship(), testScene);
    Engine::instantiate(new CleverBunker(), testScene);
    Engine::setCurrentScene(testScene);
    this->scenes.push_back(testScene);   
    
}

void Game::update(const float deltaTime) { }
