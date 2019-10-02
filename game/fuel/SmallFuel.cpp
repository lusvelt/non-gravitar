#include "../../engine/Object.hpp"
#include "SmallFuel.hpp"
#include "../../engine/Engine.hpp"
#include "../../engine/Object.hpp"

SmallFuel::SmallFuel(): Fuel(buildShape()){ }

Shape* SmallFuel::buildShape(){

    ConvexShape* shape = new ConvexShape(5);
    shape->setPoint(0, Point(0.f,0.f));
    shape->setPoint(1, Point(-5.f,0.f));
    shape->setPoint(2, Point(-8.f,-5.f));
    shape->setPoint(3, Point(-8.f,-15.f));
    shape->setPoint(4, Point(0.f,-15.f));
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Yellow);
    shape->setFillColor(Color::Red);

    return shape;
}