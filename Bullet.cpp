#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include "Engine.hpp"

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
}

void Bullet::update(const float deltaTime) {
    Engine::checkAndRemoveIfOutOfBounds(this);
}

void Bullet::onCollisionEnter(Object* collider) {
    if (!this->compareSourceTag(collider->getTag()))
        Engine::destroy(this);
}

string Bullet::getSourceTag() {
    return this->sourceTag;
}

bool Bullet::compareSourceTag(string tag) {
    return this->sourceTag == tag;
}