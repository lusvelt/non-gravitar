#include "NonGravitar.hpp"

#include "../engine/Engine.hpp"
#include "scenes/SolarSystem.hpp"
#include "miscellaneous/Spaceship.hpp"
#include "bunkers/TankBunker.hpp"

NonGravitar::NonGravitar() : Game("Non-Gravitar", WINDOW_WIDTH, WINDOW_HEIGHT) {
    score = 0;
    fuel = FUEL_START_VALUE;
    lives = LIVES_START_VALUE;

    Scene* testScene = new SolarSystem();
    Engine::instantiate(new Spaceship(), testScene);
    Engine::instantiate(new TankBunker(), testScene);
    Engine::setCurrentScene(testScene);
    this->scenes.push_back(testScene);   
}