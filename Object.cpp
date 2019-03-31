#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#include "Object.hpp"
#include "Engine.hpp"

using namespace sf;
using namespace std;

Object::Object(Shape* shape, Vector2f position, float rotation) {
    Engine::addObjectToCurrentScene(this);
    this->shape = shape;
    this->position = position;
    this->rotation = rotation;
    this->speed = Vector2f(0.f, 0.f);
    this->acceleration = Vector2f(0.f, 0.f);
    this->angularSpeed = 0;
    this->tag = "Object";
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

string Object::getTag() {
    return tag;
}

bool Object::compareTag(string tag) {
    return this->tag == tag;
}

void Object::updateTransform(const float deltaTime) {
    speed.x += acceleration.x * deltaTime;
    speed.y += acceleration.y * deltaTime;

    position.x += speed.x * deltaTime;
    position.y += speed.y * deltaTime;
    rotation += angularSpeed * deltaTime;

    shape->setPosition(position);
    shape->setRotation(rotation);
}

void Object::onCollisionEnter(Object* collider) { }

Object::~Object() {
    Engine::removeObjectFromCurrentScene(this);
}