#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "TankBunker.hpp"
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"

using namespace std;
using namespace sf;

TankBunker::TankBunker() : Bunker(buildShape(), 20, 45.f, 45.f, 1.f) {}

Shape* TankBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(8);

    shape->setPoint(0, Vector2f(-50.f, 30.f));
    shape->setPoint(1, Vector2f(-50.f, -20.f));
    shape->setPoint(2, Vector2f(-10.f, -20.f));
    shape->setPoint(3, Vector2f(-10.f, -40.f));
    shape->setPoint(4, Vector2f(10.f, -40.f));
    shape->setPoint(5, Vector2f(10.f, -20.f));
    shape->setPoint(6, Vector2f(50.f, -20.f));
    shape->setPoint(7, Vector2f(50.f, 30.f));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Magenta);
    shape->setFillColor(Color::Black);

    return shape;
}

float TankBunker::shootPoint(){
    return 45.f;
}

void TankBunker::studyFireAngle() {
    fireAngle += angularFactor;
    if (abs(fireAngle) >= maxRay)
        angularFactor *= (float)(-1);
    Bunker::setFireAngleByRotation();
}