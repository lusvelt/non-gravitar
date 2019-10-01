#include "ThreeDirectionBunker.hpp"

ThreeDirectionBunker::ThreeDirectionBunker() : Bunker(buildShape(), 4, 55.f, 10.f, .5f) {
    srand(time(NULL));
}

Shape* ThreeDirectionBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(8);

    //SHAPE:

    shape->setPoint(0, Point(-10.f, -40.f));
    shape->setPoint(1, Point(10.f, -40.f));
    shape->setPoint(2, Point(10.f, 40.f));
    shape->setPoint(3, Point(-10.f, 40.f));

    /*
    shape->setPoint(0, Point(-50.f, 30.f));
    shape->setPoint(1, Point(50.f, 30.f));
    shape->setPoint(2, Point(-30.f, -30.f));
    shape->setPoint(3, Point(-26.f, 0.f));
    shape->setPoint(4, Point(0.f, -40.f));
    shape->setPoint(5, Point(26.f, 0.f));
    shape->setPoint(6, Point(30.f, -30.f));
    //shape->setPoint(7, Point(0.f, 30.f));
*/
    //CONFIGURATION:
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::White);
    shape->setFillColor(Color::Black);

    return shape;
}

float ThreeDirectionBunker::shootPoint(){
    return 45.f;
}

void ThreeDirectionBunker::studyFireAngle() {
    int direction = rand()%3;
    if(direction == 0) this->fireAngle = STANDARD_BUNKER_ANGLE;
    else if(direction == 1) this->fireAngle = -STANDARD_BUNKER_ANGLE;
    else this->fireAngle = 0.f;
    Bunker::studyFireAngle(); 
}