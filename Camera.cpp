#include "Camera.hpp"

#include "Engine.hpp"

Camera::Camera(const void (*updateFunction)(Camera*, const float, vector<Object*>*)) {
    this->position = Vector2f(0.f, 0.f);
    this->updateFunction = updateFunction;
}

Vector2f Camera::getPosition() {
    return this->position;
}

void Camera::setPosition(Vector2f position) {
    this->position = position;
}

void Camera::update(const float deltaTime) {
    this->updateFunction(this, deltaTime, Engine::getCurrentScene()->getObjects());
}