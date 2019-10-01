#include "TwoDirectionBunker.hpp"

TwoDirectionBunker::TwoDirectionBunker() : Bunker(buildShape(), 4, 55.f, 10.f, .5f) {
    srand(time(NULL));
}

Shape* TwoDirectionBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(8);

    /*shape->setPoint(0, Point(50.f, 30.f));
    shape->setPoint(1, Point(50.f, -20.f));
    shape->setPoint(2, Point(25.f, 0.f));
    shape->setPoint(3, Point(5.f, -40.f));
    shape->setPoint(4, Point(-5.f, -40.f));
    shape->setPoint(5, Point(-25.f, 0.f));
    shape->setPoint(6, Point(-50.f, -20.f));
    shape->setPoint(7, Point(-50.f, 30.f));*/

    //SHAPE:

    shape->setPoint(0, Point(-10.f, -40.f));
    shape->setPoint(1, Point(10.f, -40.f));
    shape->setPoint(2, Point(10.f, 40.f));
    shape->setPoint(3, Point(-10.f, 40.f));

    /*
    shape->setPoint(0, Point(-50.f, 30.f));
    shape->setPoint(1, Point(50.f, 30.f));
    shape->setPoint(2, Point(-50.f, -40.f));
    shape->setPoint(3, Point(-35.f, -30.f));
    shape->setPoint(4, Point(-45.f, 30.f));
    shape->setPoint(5, Point(15.f, 30.f));
    shape->setPoint(6, Point(15.f, -20.f));
    shape->setPoint(7, Point(50.f, -30.f));
*/
    //CONFIGURATION:
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Yellow);
    shape->setFillColor(Color::Black);

    return shape;
}

float TwoDirectionBunker::shootPoint(){
    return 60.f;
}

void TwoDirectionBunker::studyFireAngle() {
    int direction = rand()%2;
    if(direction == 0) this->fireAngle = STANDARD_BUNKER_ANGLE;
    else this->fireAngle = -STANDARD_BUNKER_ANGLE;
    Bunker::studyFireAngle();
}