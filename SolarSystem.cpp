#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <random>
#include "Camera.hpp"
#include "Scene.hpp"
#include "Planet.hpp"
#include "Declarations.hpp"
#include "SolarSystem.hpp"
#include "Bunker.hpp"
#include "TankBunker.hpp"
#include "CleverBunker.hpp"
#include "DoubleShootBunker.hpp"


using namespace std;
using namespace sf;



const void cameraFunction1(Camera* camera, const float deltaTime, vector<Object*> *sceneObjects) {}

SolarSystem::SolarSystem() : Scene(cameraFunction1){
    int nPlanets = 9;
    int nColumns = 3;
    this->addObject(new Spaceship());
    this->addObject(new DoubleShootBunker());
    //this->addObject(new TankBunker());
    this->Division(nPlanets,nColumns);
    //vectorPlanets.push_back(new Planet(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)));
}

const void SolarSystem::Division(int nPlanets,int nColumns){
    int sizeBlockx= WINDOW_WIDTH/nColumns;
    int sizeBlocky= WINDOW_HEIGHT/nColumns;
    int xstart=0;
    int ystart=0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> disx(0, sizeBlockx);
    uniform_int_distribution<> disy(0, sizeBlocky);
    //int xend=0;
    //int yend=0;
    for(int i=0; i< nPlanets/nColumns; i++){
        for(int j=0;j<nPlanets/nColumns;j++){
            xstart= j * sizeBlockx;
            ystart= i * sizeBlocky;
            //xend= xstart + sizeBlockx;
            //yend= ystart + sizeBlocky; 
            vectorPlanets.push_back(new Planet(Vector2f(xstart + disx(gen), ystart + disy(gen))));
        }
    }
} 

void SolarSystem::update(const float deltaTime) { 

};
 