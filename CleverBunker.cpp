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

CleverBunker::CleverBunker() : Bunker(buildShape(), 5, 45.f, 45.f, 10000.f) {}

Shape* CleverBunker::buildShape() {

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
    shape->setOutlineColor(Color::Blue);
    shape->setFillColor(Color::Black);

    return shape;
}

float CleverBunker::shootPoint(){
    //TODO PUNTO DA CUI PARTE IL PROIETTILE
    return 45.f;
}

void CleverBunker::studyFireAngle(){
    float angle = 90.f;
    Vector2f spaceshipPosition = Engine::getObjectByTag("Spaceship")->getPosition();
    if(this->position.x != spaceshipPosition.x)
     angle = (atan(abs((this->position.y - spaceshipPosition.y)/(this->position.x - spaceshipPosition.x)))/M_PI)*180;
    this->fireAngle -= angle;
    cout << this->fireAngle << endl;
}