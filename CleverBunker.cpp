#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "CleverBunker.hpp"
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"
#include "Spaceship.hpp"
#include "Engine.hpp"

using namespace std;
using namespace sf;

CleverBunker::CleverBunker() : Bunker(buildShape(), 5, 45.f, 45.f, .10f) {
    this->bulletSpeed = 700.f;
}

Shape* CleverBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(11);

    shape->setPoint(0, Vector2f(20.f, 30.f));
    shape->setPoint(1, Vector2f(30.f, -10.f));
    shape->setPoint(2, Vector2f(50.f, -40.f));
    shape->setPoint(3, Vector2f(40.f, -40.f));
    shape->setPoint(4, Vector2f(20.f, -10.f));
    shape->setPoint(5, Vector2f(0.f, 20.f));
    shape->setPoint(6, Vector2f(-20.f, -10.f));
    shape->setPoint(7, Vector2f(-40.f, -40.f));
    shape->setPoint(8, Vector2f(-50.f, -40.f));
    shape->setPoint(9, Vector2f(-30.f, -10.f));
    shape->setPoint(10, Vector2f(-20.f, 30.f));
    //MODIFICA


    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Blue);
    shape->setFillColor(Color::Black);

    return shape;
}

float CleverBunker::shootPoint(){
    return 15.f;
}

void CleverBunker::studyFireAngle(){
    float angle = 90.f;
    Vector2f delta = Engine::getObjectByTag("Spaceship")->getPosition() - this->position;
    angle = atan(delta.y/delta.x)/M_PI*180;
    this->fireAngle = 270 - angle;
    if(delta.x < 0) this->fireAngle -= 180;
}