#include "TwoDirectionBunker.hpp"

TwoDirectionBunker::TwoDirectionBunker() : Bunker(buildShape(), 4, 55.f, 10.f, .5f) {
    srand(time(NULL));
}

Shape* TwoDirectionBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(5);

    //SHAPE:

    shape->setPoint(0, Vector2f(-25.f,10.f));
    shape->setPoint(1, Vector2f(25.f,10.f));
    shape->setPoint(2, Vector2f(12.5f,-20.f));
    shape->setPoint(3, Vector2f(0.f,0.f));
    shape->setPoint(4, Vector2f(-12.5f,-20.f));

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