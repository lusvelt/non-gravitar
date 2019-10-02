#include "Bullet.hpp"

#include "../../engine/Engine.hpp"

Bullet::Bullet(Shape* shape, Point position, Point speed):
    Object(shape, position, 0.f) {
    this->speed = speed;
    this->tag = "Bullet";
    this->deleteIfOutOfBounds = true;
}

void Bullet::update() { }

void Bullet::onBoundHit(Bound bound) {
    Engine::destroy(this);
}

bool Bullet::collidesWith(Object* obj) {
    if (obj->compareTag("Surface"))
        return obj->collidesWith(this);
    else return Object::collidesWith(obj);
}