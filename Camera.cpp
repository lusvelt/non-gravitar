#include "Camera.hpp"
#include <SFML/System.hpp>

Camera::Camera(const void (*updateFunction)(Camera*, const float)) {
    this->position = Vector2f(0.f, 0.f);
    this->updateFunction = updateFunction;
}

void Camera::setPosition(Vector2f position) {
    this->position = position;
}

void Camera::update(const float deltaTime) {
    this->updateFunction(this, deltaTime);
}