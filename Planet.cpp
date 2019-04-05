#include "Planet.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include <vector>

Shape* Planet::buildShape() {
    srand(time(NULL));
    float diameter= rand()%70 + 10;
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
    Scene(cameraFunction2) { }

void Planet::update(const float deltaTime) { }