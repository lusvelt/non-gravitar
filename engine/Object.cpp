#include "Object.hpp"

#include "Engine.hpp"

Object::Object(Shape* shape, Vector2f position, float rotation) {
    this->shape = shape;
    this->position = position;
    this->rotation = rotation;
    this->speed = Vector2f(0.f, 0.f);
    this->acceleration = Vector2f(0.f, 0.f);
    this->angularSpeed = 0;
    this->tag = "Object";
    this->prevPointer = NULL;
    this->deleteIfOutOfBounds = false;
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

void Object::updateTransform() {
    const float deltaTime = Engine::getDeltaTime();
    
    speed += deltaTime * acceleration;
    position += deltaTime * speed;
    rotation += deltaTime * angularSpeed;

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

void Object::update() { }

void Object::setPosition(Vector2f position) {
    this->position = position;
}

void Object::setSpeed(Vector2f speed) {
    this->speed = speed;
}

bool Object::isOutOfBounds() {
    Vector2f objPosition = this->position - Engine::getCurrentScene()->getCamera()->getPosition();
    Game* game = Engine::getGame();
    return objPosition.x < -game->getOutOfBoundsOffsetX() ||
           objPosition.x > game->getViewWidth() + game->getOutOfBoundsOffsetX() ||
           objPosition.y < -game->getOutOfBoundsOffsetY() ||
           objPosition.y > game->getViewHeight() + game->getOutOfBoundsOffsetY();
}

bool Object::shouldBeDeletedIfOutOfBounds() {
    return deleteIfOutOfBounds;
}