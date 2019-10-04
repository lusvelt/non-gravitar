#include "BigFuel.hpp"
#include "../../engine/Engine.hpp"
#include "../../engine/Object.hpp"

BigFuel::BigFuel(): Fuel(buildShape()){ 
    this->fuelAmount = 500;
}

Shape* BigFuel:: buildShape(){

    ConvexShape* shape= new ConvexShape(5);
    shape->setPoint(0, Point(0.f,0.f));
    shape->setPoint(1, Point(-15.f,0.f));
    shape->setPoint(2, Point(-15.f,-25.f));
    shape->setPoint(3, Point(-10.f,-30.f));
    shape->setPoint(4, Point(0.f,-30.f));
    shape->setOutlineThickness(3.f);
    shape->setOutlineColor(Color::Yellow);
    shape->setFillColor(Color::Red);

    return shape;
}