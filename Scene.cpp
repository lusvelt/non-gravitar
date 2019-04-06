#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"
#include "Engine.hpp"
#include <vector>
#include <iostream>

Scene::Scene(const void (*cameraFunction)(Camera*, const float, vector<Object*>*)) {
    Engine::startPreparingScene();
    this->camera = new Camera(cameraFunction);
    this->objects = vector<Object*>();
}

Camera* Scene::getCamera() {
    return this->camera;
}

vector<Object*> *Scene::getObjects() {
    return &this->objects;
}

void Scene::addObject(Object* obj) {
    this->objects.push_back(obj);
}

void Scene::update(const float deltaTime) {
    for (vector<Object*>::iterator obj = this->objects.begin(); obj != this->objects.end(); ++obj)
        (*obj)->update(deltaTime);
}