#include "SolarSystem.hpp"

#include "../../engine/Engine.hpp"
#include "../cameras/FixedCamera.hpp"

SolarSystem::SolarSystem() : Scene(new FixedCamera(), Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)) {
    this->type = "SolarSystem";
    srand(time(NULL));
    this->generatePlanets();
}

const void SolarSystem::generatePlanets() {
    int sizeBlockx = (WINDOW_WIDTH / N_COLUMNS) - MARGIN;
    int sizeBlocky = (WINDOW_HEIGHT / N_COLUMNS) - MARGIN;
    int xStart = 0;
    int yStart = 0;
    int count = 0;
    for (int i = 0; i < N_BLOCKS / N_COLUMNS; i++) {
        for(int j = 0; j < N_BLOCKS / N_COLUMNS; j++) {
            xStart = (j * sizeBlockx) + MARGIN;
            yStart = (i * sizeBlocky) + MARGIN;
            bool emptyBlock = rand() % 2;
            Vector2f position = Vector2f(rand() % (sizeBlockx - MARGIN)+ xStart, rand() % (sizeBlocky - MARGIN) + yStart);
            if ((i == 1 && j == 1) || !emptyBlock) { 
                count++;
                if (count > 5)
                   planets.push_back((Planet*) Engine::instantiate(new Planet(position), this));
            } else
                planets.push_back((Planet*) Engine::instantiate(new Planet(position), this));
        }
    }
} 

void SolarSystem::update() { }
 
