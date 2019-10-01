#include "Line.hpp"

Line::Line(float m, float q) {
    this->m = m;
    this->q = q;
}

Line::Line(Point p1, Point p2) {
    this->m = (p2.y - p1.y) / (p2.x - p1.x);
    this->q = p1.y - m * p1.x;
}

float Line::getDistance(Point p) {
    return abs(m * p.x - p.y + q) / sqrt(pow(m, 2) + 1);
}

Line* Line::getPerpendicularThroughPoint(Point p) {
    float m = - 1 / this->m;
    float q = p.y - m * p.x;
    return new Line(m, q);
}

float Line::evaluateY(float x) {
    return m * x + q;
}