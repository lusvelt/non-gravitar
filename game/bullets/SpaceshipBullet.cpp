#include "SpaceshipBullet.hpp"

#include "../../engine/Engine.hpp"

Shape *SpaceshipBullet::buildShape() {
    CircleShape* shape = new CircleShape(2, 12);
    shape->setFillColor(Color::Yellow);
    return shape;
}

SpaceshipBullet::SpaceshipBullet(Point position, Vector speed) : Bullet(buildShape(), position, speed) {
    this->tag = "SpaceshipBullet";
}

void SpaceshipBullet::onCollisionEnter(Object *collider) {
    if (!collider->compareTag(this->tag) && !collider->compareTag("Spaceship"))
        Engine::destroy(this);
}