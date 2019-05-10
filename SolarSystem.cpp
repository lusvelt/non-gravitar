#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Camera.hpp"
#include "Scene.hpp"
#include "Planet.hpp"
#include "Declarations.hpp"
#include "SolarSystem.hpp"
#include "Bunker.hpp"
#include "CleverBunker.hpp"
#include "DoubleShootBunker.hpp"

using namespace std;
using namespace sf;

const void cameraFunction1(Camera* camera, const float deltaTime, vector<Object*> *sceneObjects) {}

// TODO: mettere nBlocks e nColumns in Declarations
SolarSystem::SolarSystem() : Scene(cameraFunction1){
    srand(time(NULL));
    int nBlocks = 9;
    int nColumns = 3;
    this->generatePlanets(nBlocks, nColumns);
}

// TODO: che cos'è quel 30 ???
const void SolarSystem::generatePlanets(int nBlocks,int nColumns) {
    int sizeBlockx = (WINDOW_WIDTH / nColumns) - 30;
    int sizeBlocky = (WINDOW_HEIGHT / nColumns) - 30;
    int xStart = 0;
    int yStart = 0;
    int count = 0;
    for (int i = 0; i < nBlocks / nColumns; i++) {
        for(int j = 0; j < nBlocks / nColumns; j++) {
            xStart = (j * sizeBlockx) + 30;
            yStart = (i * sizeBlocky) + 30;
            bool emptyBlock = rand() % 2;
            Vector2f position = Vector2f(rand() % sizeBlockx + xStart, rand() % sizeBlocky + yStart);
            if ((i == 1 && j == 1) || !emptyBlock) { 
                count++;
                if (count > 5)
                   planets.push_back((Planet*) Engine::instantiate(new Planet(position), this));
            } else
                planets.push_back((Planet*) Engine::instantiate(new Planet(position), this));
        }
    }
} 

void SolarSystem::update(const float deltaTime) { 

}
 
