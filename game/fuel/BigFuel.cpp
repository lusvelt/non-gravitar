#include "BigFuel.hpp"
#include "../../engine/Engine.hpp"
#include "../../engine/Object.hpp"

BigFuel::BigFuel(): Fuel(buildShape()){ }

Shape* BigFuel:: buildShape(){

    ConvexShape* Shape= new ConvexShape(5);
    Shape->setPoint(0, Point(0.f,0.f));
    Shape->setPoint(1, Point(-10.f,0.f));
    Shape->setPoint(2, Point(-15.f,-10.f));
    Shape->setPoint(3, Point(-15.f,-30.f));
    Shape->setPoint(4, Point(0.f,-30.f));
    shape->setOutlineThickness(3.f);
    shape->setOutlineColor(Color::Yellow);
    shape->setFillColor(Color::Red);

    return Shape;
}