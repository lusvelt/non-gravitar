#include "ThreeDirectionBunker.hpp"

ThreeDirectionBunker::ThreeDirectionBunker() : Bunker(buildShape(), 4, 55.f, 10.f, .5f) {
    srand(time(NULL));
}

Shape* ThreeDirectionBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(7);

    //SHAPE:

    shape->setPoint(0, Vector2f(-25.f,20.f));
    shape->setPoint(1, Vector2f(25.f,20.f));
    shape->setPoint(2, Vector2f(20.f,-10.f));
    shape->setPoint(3, Vector2f(10.f,0.f));
    shape->setPoint(4, Vector2f(0.f,-30.f));
    shape->setPoint(5, Vector2f(-10.f,0.f));
    shape->setPoint(6, Vector2f(-20.f,-10.f));

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