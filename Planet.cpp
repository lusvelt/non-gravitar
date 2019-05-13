#include "Planet.hpp"
#include "Engine.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include <vector>

Shape* Planet::buildShape() {
    float radius = rand() % 20 + 10;
    CircleShape* shape = new CircleShape(radius);

    shape->setFillColor(Color(rand()%255, rand()%255, rand()%255));
    shape->setOutlineThickness((rand()%2)+1);
    shape->setOutlineColor(Color(rand()%255, rand()%255, rand()%255));
    return shape;
};

void Planet::onCollisionEnter(Object* collider){
    if (collider->compareTag("Spaceship")){
        this->addObject(collider, Vector2f(0.f, 0.f));
        // Aggiungere lineette del pianeta, bunker, fuels e cose varie
        Engine::setCurrentScene(this);
    }
}

const void followSpaceship(Camera* camera, const float deltaTime, vector<Object*> *sceneObjects) {
    Vector2f spaceshipPosition = Engine::getObjectByTag("Spaceship")->getPosition();
    camera->setPosition(Vector2f(spaceshipPosition.x - WINDOW_WIDTH / 2, spaceshipPosition.y - WINDOW_HEIGHT / 2));
}

Planet::Planet(Vector2f position): 
    Object(Planet::buildShape(), position, 0.f),
    Scene(followSpaceship) {
        this->tag = "Planet";
        this->radius = ((CircleShape*) this->shape)->getRadius() * PLANET_SCALE;
        int nPoints = 2 * M_PI * (float) radius / PIXELS_PER_POINT;
        int rangeX = PIXELS_PER_POINT / 2 * PLANET_POINT_RANGE_SCALE_X;
        int rangeY = PIXELS_PER_POINT / 2 * PLANET_POINT_RANGE_SCALE_Y;
        for (int i = 0; i < nPoints; i++) {
            int offsetX = rand() % rangeX - rangeX / 2;
            int offsetY = rand() % rangeY - rangeY / 2;
            float offsetAngle = offsetX / radius;
            float offsetDistance = offsetY;
            float currentAngle = (float) i * 2 * M_PI / nPoints;
            float realAngle = currentAngle + offsetAngle;
            float realDistance = radius + offsetDistance;
            Vector2f point = realDistance * Vector2f(cos(realAngle), sin(realAngle));
            this->points.push_back(point);
        }
        // TODO: creare la classe Line e qua istanziare le linee
    }

void Planet::update(const float deltaTime) { }
