#include <iostream>
#include <cmath>
#include <vector>
#include "Camera.hpp"
#include "Scene.hpp"
#include "Planet.hpp"
#include <SFML/Window.hpp>
#include "Declarations.hpp"
#include "SolarSystem.hpp"

using namespace std;
using namespace sf;

const void cameraFunction1(Camera* camera, const float deltaTime, vector<Object*> *sceneObjects) {}

SolarSystem::SolarSystem() : Scene(cameraFunction1){
    srand(time(NULL));
    int nPlanets = rand()%MIN_PLANETS + MAX_PLANETS;
    int nColumns = nPlanets;
    nPlanets = nPlanets * nPlanets ;

    for(int i=0; i<=nPlanets; i++){
        planets.push_back(new Planet(Vector2f(rand()%WINDOW_WIDTH, rand()%WINDOW_HEIGHT)));
    }

}

const void Division(int nPlanets,int nColumns){
    int sizeBlockx= WINDOW_WIDTH/nColumns;
    int sizeBlocky= WINDOW_HEIGHT/nColumns;
    int xstart=0;
    int ystart=0;
    int xend=0;
    int yend=0;
    for(int i=0; i<= nPlanets; i++){
        for(int j=0;j<=nPlanets;j++){
            xstart= j * sizeBlockx;
            ystart= i * sizeBlocky;
            xend= xstart + sizeBlockx;
            yend= ystart + sizeBlocky; 
        }
        planets.push_back(new Planet(Vector2f(rand()%xend+xstart, rand()%yend+ystart)));

        
    }



}

void SolarSystem::update(const float deltaTime) { 

};
