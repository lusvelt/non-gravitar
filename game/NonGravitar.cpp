#include "NonGravitar.hpp"

#include "../engine/Engine.hpp"
#include "scenes/SolarSystem.hpp"
#include "spaceship/Spaceship.hpp"
#include "spaceship/TractorBeam.hpp"
#include "spaceship/MovingLight.hpp"
#include "info/FuelInfo.hpp"
#include "info/Lives.hpp"
#include "info/Score.hpp"

NonGravitar::NonGravitar() : Game("Non-Gravitar", WINDOW_WIDTH, WINDOW_HEIGHT) {
    score = 0;
    Scene* solarSystem = new SolarSystem();
    Spaceship* spaceship = new Spaceship();
    TractorBeam* tractorBeam = new TractorBeam();
    MovingLight* movingLight = new MovingLight();
    spaceship->addChild(tractorBeam);
    spaceship->addChild(movingLight);
    spaceship->setPosition(Point(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    Engine::instantiate(spaceship, solarSystem);
    Engine::setCurrentScene(solarSystem);
    this->scenes.push_back(solarSystem);

    int lives = ((Spaceship*) Engine::getObjectByTag("Spaceship"))->getLives();
    Engine::addInfo(new FuelInfo());
    Engine::addInfo(new Score(score));
    Engine::addInfo(new Lives(lives));
}

void NonGravitar::addScore(int score) {
    this->score += score;
}

int NonGravitar::getScore() {
    return score;
}

void NonGravitar::generateSolarSystem() {
    // TODO
}