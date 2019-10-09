#include "SolarSystem.hpp"

#include "../../engine/Engine.hpp"
#include "../cameras/FixedCamera.hpp"
#include "../NonGravitar.hpp"

SolarSystem::SolarSystem() : Scene(new FixedCamera(), Point(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)) {
    this->sceneType = "SolarSystem";
    srand(time(NULL));
    planetCount = 0;
    this->generatePlanets();
}

void SolarSystem::addPlanet(Planet* planet) {
    planetCount++;
    planets.push_back(planet);
}

// Divido la schermata in una griglia
const void SolarSystem::generatePlanets() {
    Vector sizeBlock = Vector(WINDOW_WIDTH / N_COLUMNS, WINDOW_HEIGHT / N_ROWS);
    Point start;
    Point end;

    int count = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> disE(0, 1);
    uniform_int_distribution<> disR(PLANET_MIN_RADIUS, PLANET_MAX_RADIUS);
    for (int i = 0; i < N_ROWS; i++) {
        for(int j = 0; j < N_COLUMNS; j++) {
            start = Point(j * sizeBlock.x, i * sizeBlock.y);
            end = start + sizeBlock;
            bool emptyBlock = (disE(gen) || (i == (N_ROWS - 1) / 2 && j == (N_COLUMNS - 1) / 2) || (i == 0 && j == 0)) && !(i == 0 && j == 1);

            if (!emptyBlock) {
                int radius = disR(gen);
                int scaledRadius = radius / PLANET_SCALE;
                uniform_int_distribution<> disX(scaledRadius, sizeBlock.x - scaledRadius);
                uniform_int_distribution<> disY(scaledRadius, sizeBlock.y - scaledRadius);
                Point position = start + Vector(disX(gen), disY(gen));
                
                addPlanet((Planet *)Engine::instantiate(new Planet(position, radius), this));
            }
        }
    }
} 

void SolarSystem::onLoad() {
    for (int i = 0; i < planets.size(); i++) {
        Planet* planet = planets.at(i);
        if (planet->hasNoBunkers()) {
            planets.erase(remove(planets.begin(), planets.end(), planet), planets.end());
            ((NonGravitar*) Engine::getGame())->addScore(planet->getScore());
            Engine::destroy(planet);
            planetCount--;
        }
    }
    if (planetCount <= 0)
        ((NonGravitar*) Engine::getGame())->generateSolarSystem();
}

void SolarSystem::update() { }
 
