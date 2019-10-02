#include "DoubleShootBunker.hpp"

DoubleShootBunker::DoubleShootBunker() : Bunker(buildShape(), 5, 55.f, 10.f, .5f) {
    this->direction = 1;
    this->fireAngle = 10.f;
    this->absFireAngle = 0;
    this->shot = 1;
}

Shape* DoubleShootBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(5);

    //SHAPE:

    shape->setPoint(0, Point(0.f, 0.f));
    shape->setPoint(1, Point(50.f, 0.f));
    shape->setPoint(2, Point(20.f, -20.f));
    shape->setPoint(3, Point(25.f, -40.f));
    shape->setPoint(4, Point(30.f, -20.f));


    //CONFIGURATION:
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Green);
    shape->setFillColor(Color::Black);

    return shape;
}

Point DoubleShootBunker::shootPoint(){
    return Point(25.f, -40.f);
}

void DoubleShootBunker::studyFireAngle() {
    this->direction = -(this->direction);
    this->fireAngle = this->absFireAngle + this->angularFactor * this->shot * this->direction;
    if(abs(this->fireAngle) >= this->maxRay) this->shot = 0;
    this->shot ++;
    Bunker::studyFireAngle();
}