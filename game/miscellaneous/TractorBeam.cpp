#include "TractorBeam.hpp"
#include "../../engine/Object.hpp"
#include "../../engine/Engine.hpp"
#include "Spaceship.hpp"

Shape* TractorBeam::buildShape() {
    ConvexShape* shape = new ConvexShape(3);
    shape->setPoint(0, Vector2f(-70.f, 20.f));
    shape->setPoint(1, Vector2f(-70.f, -20.f));
    shape->setPoint(2, Vector2f(0.f, 0.f));
    shape->setFillColor(Color::Transparent);
    shape->setOutlineThickness(2.f);
    shape->setOutlineColor(Color::White);
    return shape;
};

TractorBeam::TractorBeam():
    Object(TractorBeam::buildShape(),position, rotation){
        this->tag = "TractorBeam";
    }

void TractorBeam::update() {
    Object* sp=Engine::getObjectByTag("Spaceship");
    this->position= sp->getPosition();
    this->rotation= sp->getRotation();
    Vector2f pos = Engine::getObjectByTag("Spaceship")->getPosition();
    this->position = pos;


 }