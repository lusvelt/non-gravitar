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

    shape->setPoint(0, Point(-25.f, 20.f));
    shape->setPoint(1, Point(25.f, 20.f));
    shape->setPoint(2, Point(-5.f, 0.f));
    shape->setPoint(3, Point(0.f, -20.f));
    shape->setPoint(4, Point(5.f, 0.f));


    //CONFIGURATION:
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Green);
    shape->setFillColor(Color::Black);

    return shape;
}

float DoubleShootBunker::shootPoint(){
    //TODO PUNTO DA CUI PARTE IL PROIETTILE
    return 45.f;
}

void DoubleShootBunker::studyFireAngle() {
    this->direction = -(this->direction);
    this->fireAngle = this->absFireAngle + this->angularFactor * this->shot * this->direction;
    if(abs(this->fireAngle) >= this->maxRay) this->shot = 0;
    this->shot ++;
    Bunker::studyFireAngle();
}