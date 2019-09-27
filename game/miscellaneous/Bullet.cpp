#include "Bullet.hpp"

#include "../../engine/Engine.hpp"

Shape* Bullet::buildShape() {
    CircleShape* shape = new CircleShape(2, 12);
    shape->setFillColor(Color::Yellow);
    return shape;
}

Bullet::Bullet(Vector2f position, Vector2f speed, string sourceTag):
    Object(Bullet::buildShape(), position, 0.f) {
    this->speed = speed;
    this->tag = "Bullet";
    this->sourceTag = sourceTag;
    this->deleteIfOutOfBounds = false;
}

void Bullet::update() { }

void Bullet::onCollisionEnter(Object* collider) {
    if (!this->compareSourceTag(collider->getTag()))
        Engine::destroy(this);
}

bool Bullet::compareSourceTag(string tag) {
    return this->sourceTag == tag;
}