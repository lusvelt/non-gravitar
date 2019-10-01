#include "Bullet.hpp"

#include "../../engine/Engine.hpp"

Shape* Bullet::buildShape() {
    CircleShape* shape = new CircleShape(2, 12);
    shape->setFillColor(Color::Yellow);
    return shape;
}

Bullet::Bullet(Point position, Point speed, string sourceTag):
    Object(Bullet::buildShape(), position, 0.f) {
    this->speed = speed;
    this->tag = "Bullet";
    this->sourceTag = sourceTag;
    this->deleteIfOutOfBounds = false;
}

void Bullet::update() { }

void Bullet::onCollisionEnter(Object* collider) {
    if (!this->compareSourceTag(collider->getTag()) && !this->compareTag(collider->getTag()))
        Engine::destroy(this);
}

bool Bullet::compareSourceTag(string tag) {
    return this->sourceTag == tag;
}

void Bullet::onBoundHit(Bound bound) {
    Engine::destroy(this);
}

bool Bullet::collidesWith(Object* obj) {
    if (obj->compareTag("Surface"))
        return obj->collidesWith(this);
    else return Object::collidesWith(obj);
}