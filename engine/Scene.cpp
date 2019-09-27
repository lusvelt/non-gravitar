#include "Scene.hpp"

Scene::Scene(Camera* camera) {
    this->type = "Scene";
    this->camera = camera;
}

Scene::Scene(Camera* camera, Vector2f entryPoint) {
    this->type = "Scene";
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

void Scene::addObject(Object* obj, Vector2f position) {
    obj->setPosition(position);
    obj->setSpeed(Vector2f(0.f, 0.f));
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
    return type;
}

bool Scene::compareType(string type) {
    return this->type == type;
}

Vector2f Scene::getEntryPoint() {
    return entryPoint;
}