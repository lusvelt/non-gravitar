#include "Object.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Object::Object(Shape* shape, Vector2f position, float rotation) {
    this->shape = shape;
    this->position = position;
    this->rotation = rotation;
    this->speed = Vector2f(0.f, 0.f);
    this->acceleration = Vector2f(0.f, 0.f);
    this->angularSpeed = 0;
}

Shape* Object::getShape() {
    return this->shape;
}

Vector2f Object::getPosition() {
    return this->position;
}

float Object::getRotation() {
    return this->rotation;
}