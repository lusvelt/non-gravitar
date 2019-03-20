#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"
#include <vector>

Scene::Scene(const void (*cameraFunction)(Camera*, const float)) {
    this->camera = new Camera(cameraFunction);
    this->objects = vector<Object*>();
}