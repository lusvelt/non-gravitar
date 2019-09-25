#include "Object.hpp"

Object::Object(Shape* shape, Vector2f position, float rotation) {
    this->shape = shape;
    this->position = position;
    this->rotation = rotation;
    this->speed = Vector2f(0.f, 0.f);
    this->acceleration = Vector2f(0.f, 0.f);
    this->angularSpeed = 0;
    this->tag = "Object";
    this->prevPointer = NULL;
}

Object::Object(Object* obj) {
    this->position = obj->position;
    this->tag = obj->tag;
    this->prevPointer = obj;
}

Object::Object(Vector2f position, float rotation) {
    this->position = position;
    this->rotation = rotation;
    this->speed = Vector2f(0.f, 0.f);
    this->acceleration = Vector2f(0.f, 0.f);
    this->angularSpeed = 0;
    this->tag = "Object";
    this->prevPointer = NULL;
}

Object::~Object() { }

Shape* Object::getShape() {
    return this->shape;
}

Vector2f Object::getPosition() {
    return this->position;
}

float Object::getPolarRadius() {
    return sqrt(pow(this->position.x, 2) + pow(this->position.y, 2));
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

Object* Object::getPrevPointer() {
    return this->prevPointer;
}

bool Object::isAClone() {
    return this->prevPointer != NULL;
}

void Object::onBoundHit(Bound bound) { }

void Object::update(const float deltaTime) { }

void Object::setPosition(Vector2f position) {
    this->position = position;
}

void Object::setSpeed(Vector2f speed) {
    this->speed = speed;
}