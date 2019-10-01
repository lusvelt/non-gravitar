#include "Surface.hpp"

Shape* Surface::buildShape() {
    float length = segment->getLength();
    RectangleShape* line = new RectangleShape(Vector2f(length, PLANET_LINE_THICKNESS));
    line->setFillColor(Color::Green);
    return line;
}

Surface::Surface(Point position, Point coordinates) :
    Object(position, atan(coordinates.y / coordinates.x) * 180 / M_PI + (coordinates.x >= 0 ? 0 : 180)) {
    this->segment = new Segment(position, position + coordinates);
    this->shape = buildShape();
    this->tag = "Surface";
}

void Surface::update() { }

bool Surface::collidesWith(Object* obj) {
    Point p = obj->getPosition();
    if (obj->compareTag("Bullet")) {
        this->getShape()->setFillColor(Color::Yellow);
        bool hit = segment->getDistance(p) < BULLET_COLLISION_RADIUS && segment->bandContains(p);
        if (hit) {
            hit = hit;
            this->getShape()->setFillColor(Color::Green);
            return true;
        } else {
            this->getShape()->setFillColor(Color::Green);
            return false;
        }
    } 
    else return Object::collidesWith(obj);
}

Segment* Surface::getSegment() {
    return segment;
}