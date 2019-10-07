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

const void SolarSystem::generatePlanets() {
    int sizeBlockx = (WINDOW_WIDTH / N_COLUMNS) - 2*MARGIN;
    int sizeBlocky = (WINDOW_HEIGHT / N_COLUMNS) -2*MARGIN;
    int xStart = 0;
    int yStart = 0;
    int count = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> disE(0, 1);
    uniform_int_distribution<> disX(0, sizeBlockx);
    uniform_int_distribution<> disY(0, sizeBlocky);
    uniform_int_distribution<> disR(PLANET_MIN_RADIUS, PLANET_MAX_RADIUS);
    for (int i = 0; i < N_BLOCKS / N_COLUMNS; i++) {
        for(int j = 0; j < N_BLOCKS / N_COLUMNS; j++) {
            xStart = (j * sizeBlockx) + MARGIN;
            yStart = (i * sizeBlocky) + MARGIN;
            bool emptyBlock = disE(gen);

            Point position = Point(disX(gen) + xStart, disY(gen) + yStart);
            if ((i == 1 && j == 1) || !emptyBlock) { 
                count++;
                if (count > 5)
                    addPlanet((Planet *)Engine::instantiate(new Planet(position, disR(gen)), this));
                } else
                addPlanet((Planet*) Engine::instantiate(new Planet(position, disR(gen)), this));
        }
    }
} 

void SolarSystem::onLoad() {
    for (int i = 0; i < planets.size(); i++) {
        Planet* planet = planets.at(i);
        if (planet->hasNoBunkers()) {
            planets.erase(remove(planets.begin(), planets.end(), planet), planets.end());
            planetCount--;
        }
    }
    if (planetCount <= 0)
        ((NonGravitar*) Engine::getGame())->generateSolarSystem();
}

void SolarSystem::update() { }
 
