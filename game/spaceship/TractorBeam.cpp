#include "TractorBeam.hpp"
#include "../../engine/Object.hpp"
#include "../../engine/Engine.hpp"
#include "Spaceship.hpp"

Shape* TractorBeam::buildShape() {
    ConvexShape* shape = new ConvexShape(4);
    shape->setPoint(0, Vector2f(-70.f, 20.f));
    shape->setPoint(1, Vector2f(-70.f, -20.f));
    shape->setPoint(2, Vector2f(-15.f, -10.f));
    shape->setPoint(3, Vector2f(-15.f, 10.f));
    shape->setFillColor(Color::Transparent);
    shape->setOutlineThickness(2.f);
    shape->setOutlineColor(Color::White);
    return shape;
};

TractorBeam::TractorBeam():
    Object(TractorBeam::buildShape()) {
        this->tag = "TractorBeam";
    }

void TractorBeam::update() {
    Spaceship* spaceship = (Spaceship*) Engine::getObjectByTag("Spaceship");
    this->position = spaceship->getPosition();
    this->rotation = spaceship->getRotation();

    if (Keyboard::isKeyPressed(Keyboard::Key::X))
        this->show();
    else
        this->hide();
    
 }