#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "Game.hpp"
#include "SolarSystem.hpp"
#include "Camera.hpp"
#include "Planet.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include "Bunker.hpp"
#include "DoubleShootBunker.hpp"

using namespace sf;

Game::Game() {
    score = 0;
    fuel = FUEL_START_VALUE;
    lives = LIVES_START_VALUE;

    Scene* testScene = new SolarSystem();
    Engine::instantiate(new Spaceship(), testScene);
    Engine::instantiate(new DoubleShootBunker(), testScene);
    Engine::setCurrentScene(testScene);
    this->scenes.push_back(testScene);   
    
}

void Game::update(const float deltaTime) { }
