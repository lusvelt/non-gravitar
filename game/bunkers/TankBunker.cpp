#include "TankBunker.hpp"

TankBunker::TankBunker() : Bunker(buildShape(), 20, 45.f, 45.f, 1.f) {
    this->bunkerPoints = 250;
}

Shape* TankBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(8);

    //SHAPE:

    shape->setPoint(0, Vector2f(0.f, 0.f));
    shape->setPoint(1, Vector2f(50.f, 0.f));
    shape->setPoint(2, Vector2f(50.f, -30.f));
    shape->setPoint(3, Vector2f(35.f, -30.f));
    shape->setPoint(4, Vector2f(35.f, -40.f));
    shape->setPoint(5, Vector2f(15.f, -40.f));
    shape->setPoint(6, Vector2f(15.f, -30.f));
    shape->setPoint(7, Vector2f(0.f, -30.f));

    //CONFIGURATION:
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Magenta);
    shape->setFillColor(Color::Black);

    return shape;
}

void TankBunker::studyFireAngle() {
    fireAngle += angularFactor;
    if (abs(fireAngle) > maxRay){
        angularFactor *= (float)(-1);}
}