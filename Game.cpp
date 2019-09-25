#include "Game.hpp"

#include "Engine.hpp"
#include "SolarSystem.hpp"
#include "Spaceship.hpp"
#include "TankBunker.hpp"

Game::Game() {
    score = 0;
    fuel = FUEL_START_VALUE;
    lives = LIVES_START_VALUE;

    Scene* testScene = new SolarSystem();
    Engine::instantiate(new Spaceship(), testScene);
    Engine::instantiate(new TankBunker(), testScene);
    Engine::setCurrentScene(testScene);
    this->scenes.push_back(testScene);   
    
}

void Game::update(const float deltaTime) { }
