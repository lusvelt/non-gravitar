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

SolarSystem::SolarSystem() : Scene(cameraFunction1){
    srand(time(NULL));
    int nBlocks = 9;
    int nColumns = 3;
    this->addObject(new Spaceship());
    this->Division(nBlocks,nColumns);
}

const void SolarSystem::Division(int nBlocks,int nColumns){
    int sizeBlockx= (WINDOW_WIDTH/nColumns) -30;
    int sizeBlocky= (WINDOW_HEIGHT/nColumns) -30;
    int xstart=0;
    int ystart=0;
    int conteggio=0;
    for(int i=0; i< nBlocks/nColumns; i++){
        for(int j=0;j<nBlocks/nColumns;j++){
            xstart= (j * sizeBlockx)+30;
            ystart= (i * sizeBlocky)+30;
            int emptyBlock= rand()%2;
            if((i == 1 && j == 1) || (emptyBlock==0)){ 
                conteggio++ ;
                if(conteggio >5){
                   vectorPlanets.push_back(new Planet(Vector2f(rand()%sizeBlockx+ xstart,rand()%sizeBlocky+ystart)));                }
           }
           else{
           vectorPlanets.push_back(new Planet(Vector2f(rand()%sizeBlockx+ xstart,rand()%sizeBlocky+ystart)));
           }
        }
    }
} 

void SolarSystem::update(const float deltaTime) { 

};
 
