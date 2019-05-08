#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "DoubleShootBunker.hpp"
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"
#include "Spaceship.hpp"

using namespace std;
using namespace sf;

DoubleShootBunker::DoubleShootBunker() : Bunker(buildShape(), 5, 10.f, 45.f, 0.30f) {}

Shape* DoubleShootBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(8);

    shape->setPoint(0, Vector2f(-50.f, -30.f));
    shape->setPoint(1, Vector2f(-30.f, 5.f));
    shape->setPoint(2, Vector2f(-10.f, 10.f));
    shape->setPoint(3, Vector2f(-10.f, 30.f));
    shape->setPoint(4, Vector2f(10.f, 30.f));
    shape->setPoint(5, Vector2f(10.f, 10.f));
    shape->setPoint(6, Vector2f(30.f, 5.f));
    shape->setPoint(7, Vector2f(50.f, -30.f));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Green);
    shape->setFillColor(Color::Black);

    return shape;
}

float DoubleShootBunker::shootPoint(){
    //TODO PUNTO DA CUI PARTE IL PROIETTILE
    return 45.f;
}

void DoubleShootBunker::studyFireAngle() {
    this->fireAngle = -(this->fireAngle);
}