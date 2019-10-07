#include "MovingLight.hpp"
#include "Spaceship.hpp"

Shape* MovingLight::buildShape() {
    CircleShape* shape = new CircleShape(2, 12);
    shape->setFillColor(Color::Magenta);
    return shape;
}

MovingLight::MovingLight() : Object(buildShape()) {
    this->tag = "MovingLight";
}

void MovingLight::update() {
    if(Spaceship::getLife() > 0){
        if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down))
            this->visible = true;
        else
            this->visible = false;
    }
    
}