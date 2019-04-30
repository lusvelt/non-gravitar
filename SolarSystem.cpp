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
    int nPlanets = 9;
    int nColumns = 3;
    this->addObject(new Spaceship());
    this->addObject(new Bunker());
    this->Division(nPlanets,nColumns);
    //vectorPlanets.push_back(new Planet(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)));
}

const void SolarSystem::Division(int nPlanets,int nColumns){
    int sizeBlockx= WINDOW_WIDTH/nColumns;
    int sizeBlocky= WINDOW_HEIGHT/nColumns;
    int xstart=0;
    int ystart=0;
    for(int i=0; i< nPlanets/nColumns; i++){
        for(int j=0;j<nPlanets/nColumns;j++){
            xstart= j * sizeBlockx;
            ystart= i * sizeBlocky;
            int emptyBlock= rand()%2;
            if((i == 1 && j == 1) || (emptyBlock==0)){  
                //aggiungere caso in cui i pianeti generati sono 0
           }
           else{
           vectorPlanets.push_back(new Planet(Vector2f(rand()%sizeBlockx+ xstart,rand()%sizeBlocky+ ystart)));
           }
        }
    }
} 

void SolarSystem::update(const float deltaTime) { 

};
 