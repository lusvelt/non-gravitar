#include "BunkerBullet.hpp"

#include "../../engine/Engine.hpp"

Shape* BunkerBullet::buildShape() {
    RectangleShape* shape = new RectangleShape(Vector(5, 5));
    shape->setFillColor(Color::Red);
    return shape;
}

BunkerBullet::BunkerBullet(Point position, Vector speed) : Bullet(buildShape(), position, speed) {
    this->tag = "BunkerBullet";
}

void BunkerBullet::onCollisionEnter(Object *collider) {
    if (!collider->compareTag("Bunker") && !collider->compareTag("LifePointsBar"))
        Engine::destroy(this);
}