#include "TankBunker.hpp"

TankBunker::TankBunker() : Bunker(buildShape(), 20, 45.f, 45.f, 1.f) {}

Shape* TankBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(8);

    //SHAPE:

    shape->setPoint(0, Point(-10.f, -40.f));
    shape->setPoint(1, Point(10.f, -40.f));
    shape->setPoint(2, Point(10.f, -20.f));
    shape->setPoint(3, Point(35.f, -20.f));
    shape->setPoint(4, Point(35.f, 30.f));
    shape->setPoint(5, Point(-35.f, 30.f));
    shape->setPoint(6, Point(-35.f, -20.f));
    shape->setPoint(7, Point(-10.f, -20.f));

    //CONFIGURATION:
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Magenta);
    shape->setFillColor(Color::Black);

    return shape;
}

float TankBunker::shootPoint(){
    return 45.f;
}

void TankBunker::studyFireAngle() {
    fireAngle += angularFactor;
    if (abs(fireAngle) > maxRay){
        angularFactor *= (float)(-1);}
    this->fireAngle -= this->getRotation();
}