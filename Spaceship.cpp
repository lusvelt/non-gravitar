#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include "Declarations.hpp"
#include "Spaceship.hpp"
#include "GameController.hpp"

using namespace std;
using namespace sf;

void Spaceship::buildShape() {
    shape.setPointCount(4);

    shape.setPoint(0, Vector2f(-3.f, 0.f));
    shape.setPoint(1, Vector2f(-10.f, 10.f));
    shape.setPoint(2, Vector2f(10.f, 0.f));
    shape.setPoint(3, Vector2f(-10.f, -10.f));

    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(Color::Blue);
    shape.setFillColor(Color::Black);
    shape.setPosition(position);
    shape.setRotation(rotation);
}

Spaceship::Spaceship() {
    position = Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    rotation = 0.f;

    speed = Vector2f(0.f, 0.f);
    acceleration = Vector2f(0.f, 0.f);
    
    buildShape();
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

void Spaceship::updateTransform() {
    float deltaTime = GameController::getDeltaTime().asSeconds();

    speed.x += acceleration.x * deltaTime;
    speed.y += acceleration.y * deltaTime;

    position.x += speed.x * deltaTime;
    position.y += speed.y * deltaTime;
    rotation += angularSpeed * deltaTime;

    shape.setPosition(position);
    shape.setRotation(rotation);
}

void Spaceship::update() {
    resetAccelerationAndAngularSpeed();
    if (Keyboard::isKeyPressed(Keyboard::Up))
        accelerateForward();
    if (Keyboard::isKeyPressed(Keyboard::Down))
        accelerateBackward();
    if (Keyboard::isKeyPressed(Keyboard::Left))
        rotateLeft();
    if (Keyboard::isKeyPressed(Keyboard::Right))
        rotateRight();
    updateTransform();
}

ConvexShape Spaceship::getShape() {
    return shape;
}