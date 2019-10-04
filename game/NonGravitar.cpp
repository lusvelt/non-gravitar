#include "NonGravitar.hpp"
//#include "bunkers/CleverBunker.hpp"

#include "../engine/Engine.hpp"
#include "scenes/SolarSystem.hpp"
#include "spaceship/Spaceship.hpp"
#include "spaceship/TractorBeam.hpp"
#include "fuel/SmallFuel.hpp"
NonGravitar::NonGravitar() : Game("Non-Gravitar", WINDOW_WIDTH, WINDOW_HEIGHT) {
    score = 0;
    fuel = FUEL_START_VALUE;
    lives = LIVES_START_VALUE;

    Scene* solarSystem = new SolarSystem();
    Spaceship* spaceship = new Spaceship();
    //CleverBunker* bunker = new CleverBunker();
    TractorBeam* tractorBeam = new TractorBeam();
    spaceship->addChild(tractorBeam);
    spaceship->setPosition(Point(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    Engine::instantiate(spaceship, solarSystem);
    //Engine::instantiate(bunker, testScene);
    Engine::setCurrentScene(solarSystem);
    this->scenes.push_back(solarSystem);
}