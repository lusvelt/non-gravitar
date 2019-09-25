#include "Planet.hpp"

#include "Scene.hpp"
#include "Engine.hpp"
#include "Camera.hpp"
#include "Line.hpp"

Shape* Planet::buildShape(float radius) {
    CircleShape* shape = new CircleShape(radius / PLANET_SCALE);

    shape->setFillColor(Color(rand()%255, rand()%255, rand()%255));
    shape->setOutlineThickness((rand()%2)+1);
    shape->setOutlineColor(Color(rand()%255, rand()%255, rand()%255));
    return shape;
};

void Planet::onCollisionEnter(Object* collider){
    if (collider->compareTag("Spaceship")){
        Engine::removeObjectFromCurrentScene(collider);
        this->addObject(collider, Vector2f(0.f, - (radius + SPACESHIP_DISTANCE_FROM_FLOOR)));
        // Aggiungere lineette del pianeta, bunker, fuels e cose varie
        Engine::setCurrentScene(this);
    }
}

const void followSpaceship(Camera* camera, const float deltaTime, vector<Object*> *sceneObjects) {
    Vector2f spaceshipPosition = Engine::getObjectByTag("Spaceship")->getPosition();
    camera->setPosition(Vector2f(spaceshipPosition.x - WINDOW_WIDTH / 2, spaceshipPosition.y - WINDOW_HEIGHT / 2));
}

float Planet::getRadius() {
    return this->radius;
}

Planet::Planet(Vector2f position): 
    Object(position, 0.f),
    Scene(followSpaceship) {
        this->type = this->tag = "Planet";
        this->radius = rand() % 2000 + 1000;
        this->shape = buildShape(radius);
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
        for (int i = 1; i <= nPoints; i++) {
            Vector2f start = this->points[(i - 1) % nPoints];
            Vector2f end = this->points[i % nPoints];
            Vector2f difference = end - start;
            Engine::instantiate(new Line(start, difference), this);
        }
    }

void Planet::update(const float deltaTime) { }
