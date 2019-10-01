#include "Segment.hpp"

Segment::Segment(Point p1, Point p2) : Line(p1, p2) {
    this->p1 = p1;
    this->p2 = p2;
}

bool Segment::bandContains(Point p) {
    Line* l1 = getPerpendicularThroughPoint(p1);
    Line* l2 = getPerpendicularThroughPoint(p2);
    // We want to assume that l2 is above l1 for each x
    if (l2->evaluateY(p1.x) < p1.y) {
        Line* tmp = l1;
        l1 = l2;
        l2 = tmp;
    }
    float y1 = l1->evaluateY(p.x);
    float y2 = l2->evaluateY(p.x);
    return y1 <= p1.y && p1.y <= p2.y;
}

Vector2f Segment::getVector() {
    return p2 - p1;
}

float Segment::getLength() {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}