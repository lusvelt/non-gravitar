#include "CleverBunker.hpp"

#include "../../engine/Engine.hpp"

CleverBunker::CleverBunker() : Bunker(buildShape(), 5, 45.f, 45.f, 0.50f) {
    this->bulletSpeed = 700.f;
}

Shape* CleverBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(12);

    //SHAPE:

    shape->setPoint(0, Point(-10.f, -40.f));
    shape->setPoint(1, Point(10.f, -40.f));
    shape->setPoint(2, Point(10.f, 40.f));
    shape->setPoint(3, Point(-10.f, 40.f));

    /*
    shape->setPoint(0, Point(-20.f, -15.f));
    shape->setPoint(1, Point(20.f, -15.f));
    shape->setPoint(2, Point(-30.f, 5.f));
    shape->setPoint(3, Point(-10.f, 25.f));
    shape->setPoint(4, Point(7.f, 15.f));
    shape->setPoint(5, Point(-20.f, 5.f));
    shape->setPoint(6, Point(-7.f, -12.f));
    shape->setPoint(7, Point(7.f, -12.f));
    shape->setPoint(8, Point(20.f, 5.f));
    shape->setPoint(9, Point(7.f, 15.f));
    shape->setPoint(10, Point(10.f, 25.f));
    shape->setPoint(11, Point(30.f, 5.f));
*/
    //CONFIGURATION:
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Blue);
    shape->setFillColor(Color::Black);

    return shape;
}

float CleverBunker::shootPoint(){
    return 15.f;
}

void CleverBunker::studyFireAngle(){
    float angle = 90.f;
    Point delta = Engine::getObjectByTag("Spaceship")->getPosition() - this->position;
    angle = atan(delta.y/delta.x)/M_PI*180;
    this->fireAngle = 270 - angle;
    if(delta.x < 0) this->fireAngle -= 180;
}