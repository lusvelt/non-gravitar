#include "FuelBar.hpp"

Shape* FuelBar::buildShape() {
    RectangleShape *shape = new RectangleShape(Point(80.f, 5.f));
    shape->setFillColor(Color::Green);
    return shape;
}

FuelBar::FuelBar() : Object(buildShape()) { }