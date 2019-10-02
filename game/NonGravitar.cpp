#include "NonGravitar.hpp"

#include "../engine/Engine.hpp"
#include "scenes/SolarSystem.hpp"
#include "spaceship/Spaceship.hpp"
#include "spaceship/TractorBeam.hpp"
#include "bunkers/CleverBunker.hpp"
#include "bunkers/TankBunker.hpp"
#include "bunkers/ThreeDirectionBunker.hpp"
#include "bunkers/TwoDirectionBunker.hpp"
#include "bunkers/DoubleShootBunker.hpp"
#include "fuel/SmallFuel.hpp"

NonGravitar::NonGravitar() : Game("Non-Gravitar", WINDOW_WIDTH, WINDOW_HEIGHT) {
    score = 0;
    fuel = FUEL_START_VALUE;
    lives = LIVES_START_VALUE;

    Scene* testScene = new SolarSystem();
    Spaceship* spaceship = new Spaceship();
    TractorBeam* tractorBeam = new TractorBeam();

    //-->
    DoubleShootBunker* bunker = new DoubleShootBunker();
    //<--

    spaceship->addChild(tractorBeam);
    Engine::instantiate(spaceship, testScene);
    Engine::instantiate(tractorBeam, testScene);

    //-->
    Engine::instantiate(bunker, testScene);
    //<--

    Engine::setCurrentScene(testScene);
    this->scenes.push_back(testScene);   
}