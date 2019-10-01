#include "Camera.hpp"

#include "Engine.hpp"

Camera::Camera() {
    this->position = Point(0.f, 0.f);
}

Point Camera::getPosition() {
    return this->position;
}

void Camera::setPosition(Point position) {
    this->position = position;
}
