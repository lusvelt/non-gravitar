#include "Scene.hpp"

Scene::Scene(Camera* camera) {
    this->sceneType = "Scene";
    this->camera = camera;
}

Scene::Scene(Camera* camera, Point entryPoint) {
    this->sceneType = "Scene";
    this->camera = camera;
    this->entryPoint = entryPoint;
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

void Scene::addObject(Object* obj, Point position) {
    obj->setPosition(position);
    obj->setSpeed(Point(0.f, 0.f));
    this->addObject(obj);
}

bool Scene::contains(Object* obj) {
    return count(this->objects.begin(), this->objects.end(), obj);
}

const void Scene::update() {
    for (vector<Object*>::iterator obj = this->objects.begin(); obj != this->objects.end(); ++obj)
        (*obj)->update();
}

string Scene::getType() {
    return sceneType;
}

bool Scene::compareType(string type) {
    return this->sceneType == type;
}

Point Scene::getEntryPoint() {
    return entryPoint;
}