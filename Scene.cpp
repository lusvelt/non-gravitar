#include "Scene.hpp"

Scene::Scene(const void (*cameraFunction)(Camera*, const float, vector<Object*>*)) {
    this->type = "Scene";
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

bool Scene::contains(Object* obj) {
    return count(this->objects.begin(), this->objects.end(), obj);
}

const void Scene::update(const float deltaTime) {
    for (vector<Object*>::iterator obj = this->objects.begin(); obj != this->objects.end(); ++obj)
        (*obj)->update(deltaTime);
}

string Scene::getType() {
    return type;
}

bool Scene::compareType(string type) {
    return this->type == type;
}