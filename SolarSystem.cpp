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

SolarSystem::SolarSystem() : Scene(cameraFunction1){ }

void SolarSystem::update(const float deltaTime) { };
