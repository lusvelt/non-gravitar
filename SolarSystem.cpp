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

using namespace std;
using namespace sf;

const void cameraFunction1(Camera* camera, const float deltaTime, vector<Object*> *sceneObjects) {}

SolarSystem::SolarSystem() : Scene(cameraFunction1){
    srand(time(NULL));
    float nPlanets = rand() % MIN_PLANETS + MAX_PLANETS;
    float nColumns = nPlanets;
    nPlanets = nPlanets * nPlanets;
    this->addObject(new Spaceship());
    this->addObject(new Bunker());
    vectorPlanets.push_back(new Planet(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)));

}

/*const void Division(int nPlanets,int nColumns){
    float sizeBlockx= WINDOW_WIDTH/nColumns;
    float sizeBlocky= WINDOW_HEIGHT/nColumns;
    float xstart=0;
    float ystart=0;
    float xend=0;
    float yend=0;
    for(int i=0; i<= nPlanets; i++){
        for(int j=0;j<=nPlanets;j++){
            xstart= j * sizeBlockx;
            ystart= i * sizeBlocky;
            xend= xstart + sizeBlockx;
            yend= ystart + sizeBlocky; 
        }
    }
}*/

void SolarSystem::update(const float deltaTime) { 

};
