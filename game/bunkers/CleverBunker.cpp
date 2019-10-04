#include "CleverBunker.hpp"

#include "../../engine/Engine.hpp"

CleverBunker::CleverBunker() : Bunker(buildShape(), 5, 45.f, 45.f, 0.50f) {
    this->bunkerPoints = 300;
    this->bulletSpeed = 700.f;
}

Shape* CleverBunker::buildShape() {

    ConvexShape* shape = new ConvexShape(12);

    //SHAPE:

    for(int i = 0; i <= 5; i = i + 1){
        shape->setPoint(i, 25.f * Point(-cos((M_PI * i)/5) + 1.f, -sin((M_PI * i)/5)));
    }

    //CONFIGURATION:
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Blue);
    shape->setFillColor(Color::Black);

    return shape;
}

void CleverBunker::studyFireAngle(){
    Point delta = Engine::getObjectByTag("Spaceship")->getPosition() - this->position;
    float angle = atan(delta.y/delta.x)*180/M_PI;
    this->fireAngle = 270-angle;
    if (delta.x < 0)
        this->fireAngle += 180;
    this->fireAngle += 90;
}