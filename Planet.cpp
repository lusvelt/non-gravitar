#include "Planet.hpp"
#include "Object.hpp"

Shape* Planet::buildShape() {
    srand(time(NULL));
    int diameter= rand()%70 + 10;
    CircleShape* shape= new CircleShape(diameter);

    shape->setFillColor(Color(rand()%255, rand()%255, rand()%255));
    shape->setOutlineThickness(rand()%20);
    shape->setOutlineColor(Color(rand()%255, rand()%255, rand()%255));

    return shape;
};

const void cameraFunction2(Camera* camera, const float deltaTime, vector<Object*> *sceneObjects) {
    Vector2f spaceshipPosition = sceneObjects->at(0)->getPosition();
    camera->setPosition(Vector2f(spaceshipPosition.x - WINDOW_WIDTH / 2, spaceshipPosition.y - WINDOW_HEIGHT / 2));
}

Planet::Planet(Vector2f position): 
    Object(Planet::buildShape(), position, 0.f),
    Scene(cameraFunction2) {
}

void Planet::update(const float deltaTime) { }