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
    int nPlantes = rand()%MAX_PLANETS + MIN_PLANETS;
    for(int i=0; i<=nPlantes; i++){
        planets.push_back(new Planet(Vector2f(rand()%WINDOW_WIDTH, rand()%WINDOW_HEIGHT)));
    }

}

void SolarSystem::update(const float deltaTime) { 

};
