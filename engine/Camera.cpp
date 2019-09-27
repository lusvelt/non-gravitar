#include "Camera.hpp"

#include "Engine.hpp"

Camera::Camera() {
    this->position = Vector2f(0.f, 0.f);
}

Vector2f Camera::getPosition() {
    return this->position;
}

void Camera::setPosition(Vector2f position) {
    this->position = position;
}
