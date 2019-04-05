#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include "Engine.hpp"

Shape* Bullet::buildShape() {
    CircleShape* shape = new CircleShape(2, 12);
    shape->setFillColor(Color::Yellow);
    return shape;
}

Bullet::Bullet(Vector2f position, Vector2f speed):
    Object(Bullet::buildShape(), position, 0.f) {
    this->speed = speed;
    this->tag = "Bullet";
}

void Bullet::update(const float deltaTime) {
    Engine::checkAndRemoveIfOutOfBounds(this);
}

void Bullet::onCollisionEnter(Object* collider) {
    string x = collider->getTag();
    if (!collider->compareTag("Spaceship") && !collider->compareTag("lifePointsBar") && !collider->compareTag("Bullet"))
        delete this;
}