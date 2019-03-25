#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"

using namespace sf;
using namespace std;

Shape* Bunker::buildShape(){
    ConvexShape* shape = new ConvexShape(8);

    //Descriviamo la forma del Bunker.
    shape->setPoint(0, Vector2f(-100.f, -60.f));
    shape->setPoint(1, Vector2f(-60.f, 10.f));
    shape->setPoint(2, Vector2f(-20.f, 20.f));
    shape->setPoint(3, Vector2f(-20.f, 60.f));
    shape->setPoint(4, Vector2f(20.f, 60.f));
    shape->setPoint(5, Vector2f(20.f, 20.f));
    shape->setPoint(6, Vector2f(60.f, 10.f));
    shape->setPoint(7, Vector2f(100.f, -60.f));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Green);
    shape->setFillColor(Color::Black);

    return shape;
};

Bunker::Bunker() : Object(Bunker::buildShape(), Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 0.f){ }

void Bunker::update(const float deltaTime) {}
