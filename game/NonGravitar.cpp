#include "NonGravitar.hpp"

#include "../engine/Engine.hpp"
#include "scenes/SolarSystem.hpp"
#include "spaceship/Spaceship.hpp"
#include "spaceship/TractorBeam.hpp"
#include "spaceship/MovingLight.hpp"
#include "info/FuelInfo.hpp"

NonGravitar::NonGravitar() : Game("Non-Gravitar", WINDOW_WIDTH, WINDOW_HEIGHT) {
    score = 0;
    fuel = FUEL_START_VALUE;
    lives = LIVES_START_VALUE;

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

    Engine::addInfo(new FuelInfo());
}