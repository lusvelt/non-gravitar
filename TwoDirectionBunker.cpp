#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "TwoDirectionBunker.hpp"
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"
#include "Spaceship.hpp"

using namespace std;
using namespace sf;

TwoDirectionBunker::TwoDirectionBunker() : Bunker(buildShape(), 4, 55.f, 10.f, .5f) {
    srand(time(NULL));
}

Shape* TwoDirectionBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(8);

    /*shape->setPoint(0, Vector2f(50.f, 30.f));
    shape->setPoint(1, Vector2f(50.f, -20.f));
    shape->setPoint(2, Vector2f(25.f, 0.f));
    shape->setPoint(3, Vector2f(5.f, -40.f));
    shape->setPoint(4, Vector2f(-5.f, -40.f));
    shape->setPoint(5, Vector2f(-25.f, 0.f));
    shape->setPoint(6, Vector2f(-50.f, -20.f));
    shape->setPoint(7, Vector2f(-50.f, 30.f));*/

    //SHAPE:
    shape->setPoint(0, Vector2f(-50.f, 30.f));
    shape->setPoint(1, Vector2f(50.f, 30.f));
    shape->setPoint(2, Vector2f(-50.f, -40.f));
    shape->setPoint(3, Vector2f(-35.f, -30.f));
    shape->setPoint(4, Vector2f(-45.f, 30.f));
    shape->setPoint(5, Vector2f(15.f, 30.f));
    shape->setPoint(6, Vector2f(15.f, -20.f));
    shape->setPoint(7, Vector2f(50.f, -30.f));

    //CONFIGURATION:
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Yellow);
    shape->setFillColor(Color::Black);

    return shape;
}

float TwoDirectionBunker::shootPoint(){
    return 60.f;
}

void TwoDirectionBunker::studyFireAngle() {
    int direction = rand()%2;
    if(direction == 0) this->fireAngle = STANDARD_BUNKER_ANGLE;
    else this->fireAngle = -STANDARD_BUNKER_ANGLE;
    Bunker::studyFireAngle();
}