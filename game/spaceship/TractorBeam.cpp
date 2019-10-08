#include "TractorBeam.hpp"
#include "../../engine/Object.hpp"
#include "../../engine/Engine.hpp"
#include "../fuel/Fuel.hpp"
#include "../NonGravitar.hpp"
#include "Spaceship.hpp"

Shape* TractorBeam::buildShape() {
    ConvexShape* shape = new ConvexShape(4);
    shape->setPoint(0, Point(-70.f, 20.f));
    shape->setPoint(1, Point(-70.f, -20.f));
    shape->setPoint(2, Point(-15.f, -10.f));
    shape->setPoint(3, Point(-15.f, 10.f));
    shape->setFillColor(Color::Transparent);
    shape->setOutlineThickness(2.f);
    shape->setOutlineColor(Color::White);
    shape->setScale(SPACESHIP_SCALE, SPACESHIP_SCALE);
    return shape;
};

TractorBeam::TractorBeam():
    Object(TractorBeam::buildShape()) {
        this->tag = "TractorBeam";
    }

void TractorBeam::update() {
    if (Keyboard::isKeyPressed(Keyboard::X) && !((NonGravitar*)Engine::getGame())->isOver()) this->show();
    else this->hide();
}

void TractorBeam::onCollisionEnter(Object* obj) {
    if (obj->compareTag("Fuel")) {
        Spaceship* spaceship = (Spaceship*) Engine::getObjectByTag("Spaceship");
        spaceship->addFuel(((Fuel*)obj)->getFuelAmount());
        // TODO: implementare addFuel(int) in Spaceship e getFuelAmount() in Fuel, ovviamente aggiungendo il campo fuelAmount
        // spaceship->addFuel(((Fuel*) obj)->getFuelAmount());
        Engine::destroy(obj);
    }
}