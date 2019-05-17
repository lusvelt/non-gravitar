#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"
#include "Engine.hpp"
#include <vector>
#include <iostream>

Scene::Scene(const void (*cameraFunction)(Camera*, const float, vector<Object*>*)) {
    this->camera = new Camera(cameraFunction);
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

void Scene::addObject(Object* obj, Vector2f position) {
    obj->setPosition(position);
    obj->setSpeed(Vector2f(0.f, 0.f));
    this->addObject(obj);
}

void Scene::update(const float deltaTime) {
    for (vector<Object*>::iterator obj = this->objects.begin(); obj != this->objects.end(); ++obj)
        (*obj)->update(deltaTime);
}