#include "Segment.hpp"

Segment::Segment(Point p1, Point p2) : Line(p1, p2) {
    this->p1 = p1;
    this->p2 = p2;
}

bool Segment::bandContains(Point p) {
    Line* l1 = getPerpendicularThroughPoint(p1);
    Line* l2 = getPerpendicularThroughPoint(p2);
    float y1 = l1->evaluateY(p.x);
    float y2 = l2->evaluateY(p.x);
    if (l2->evaluateY(p1.x) >= p1.y)
        return y1 <= p.y && p.y <= y2;
    else
        return y2 <= p.y && p.y <= y1;
}

Vector2f Segment::getVector() {
    return p2 - p1;
}

float Segment::getLength() {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

Point Segment::getP1(){
    return this->p1;
}

Point Segment::getP2(){
    return this->p2;
}

