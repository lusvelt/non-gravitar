#include "Line.hpp"

Shape* Line::buildShape(Vector2f coordinates) {
    float length = sqrt(pow(coordinates.x, 2) + pow(coordinates.y, 2));
    RectangleShape* line = new RectangleShape(Vector2f(length, PLANET_LINE_THICKNESS));
    line->setFillColor(Color::Green);
    return line;
}

Line::Line(Vector2f position, Vector2f coordinates) :
    Object(position, atan(coordinates.y / coordinates.x) * 180 / M_PI + (coordinates.x >= 0 ? 0 : 180)) {
    this->shape = buildShape(coordinates);
}

void Line::update(const float deltaTime) { }