#include <cmath>
#include <SFML/Window.hpp>
#include "Declarations.hpp"
#include "Spaceship.hpp"
#include "Game.hpp"
#include "Bullet.hpp"
#include "Engine.hpp"

using namespace sf;

Shape* Spaceship::buildShape() {
    ConvexShape* shape = new ConvexShape(4);

    shape->setPoint(0, Vector2f(-3.f, 0.f));
    shape->setPoint(1, Vector2f(-10.f, 10.f));
    shape->setPoint(2, Vector2f(10.f, 0.f));
    shape->setPoint(3, Vector2f(-10.f, -10.f));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Blue);
    shape->setFillColor(Color::Black);

    return shape;
}

Spaceship::Spaceship():
    Object(Spaceship::buildShape(), Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 0.f) {
    this->shootCd = 0;
    this->tag = "Spaceship";
}

void Spaceship::resetAccelerationAndAngularSpeed() {
    acceleration.x = 0.f;
    acceleration.y = 0.f;
    angularSpeed = 0.f;
}

void Spaceship::accelerateForward() {
    acceleration.x = ACCELERATION_MODULE * cos(rotation * M_PI / 180);
    acceleration.y = ACCELERATION_MODULE * sin(rotation * M_PI / 180);
}

void Spaceship::accelerateBackward() {
    acceleration.x = -ACCELERATION_MODULE * cos(rotation * M_PI / 180);
    acceleration.y = -ACCELERATION_MODULE * sin(rotation * M_PI / 180);
}

void Spaceship::rotateLeft() {
    angularSpeed = -ANGULAR_SPEED_MODULE;
}

void Spaceship::rotateRight() {
    angularSpeed = ANGULAR_SPEED_MODULE;
}


void Spaceship::update(const float deltaTime) {
    resetAccelerationAndAngularSpeed();
    if (Keyboard::isKeyPressed(Keyboard::Up))
        accelerateForward();
    if (Keyboard::isKeyPressed(Keyboard::Down))
        accelerateBackward();
    if (Keyboard::isKeyPressed(Keyboard::Left))
        rotateLeft();
    if (Keyboard::isKeyPressed(Keyboard::Right))
        rotateRight();
    if (Keyboard::isKeyPressed(Keyboard::Space) && shootCd <= 0)
        shoot();
    
    if (shootCd > 0)
        shootCd -= deltaTime;
}

void Spaceship::shoot() {
    Vector2f versor = Vector2f(cos(this->rotation * M_PI / 180), sin(this->rotation * M_PI / 180));
    Bullet *bullet = new Bullet(this->position + 10.f * versor, this->speed + BULLET_BASE_SPEED * versor, tag);
    this->shootCd = SPACESHIP_SHOOT_COOLDOWN;
}

void Spaceship::onBoundHit(Bound bound) {
    if (bound == LEFT_BOUND || bound == RIGHT_BOUND)
        speed = Vector2f(-speed.x, speed.y);
    else if (bound == TOP_BOUND || bound == BOTTOM_BOUND)
        speed = Vector2f(speed.x, -speed.y);
}

