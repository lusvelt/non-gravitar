#include "Planet.hpp"

#include "../../engine/Scene.hpp"
#include "../../engine/Engine.hpp"
#include "../cameras/FollowCamera.hpp"
#include "../scenes/Surface.hpp"

Shape* Planet::buildShape() {
    CircleShape* shape = new CircleShape(radius / PLANET_SCALE);

    shape->setFillColor(Color(rand()%255, rand()%255, rand()%255));
    shape->setOutlineThickness((rand()%2)+1);
    shape->setOutlineColor(Color(rand()%255, rand()%255, rand()%255));
    return shape;
};

void Planet::onCollisionEnter(Object* collider){
    if (collider->compareTag("Spaceship"))
        Engine::setCurrentSceneKeepingObject(this, collider);
}

const void followSpaceship(Camera* camera, vector<Object*> *sceneObjects) {
    Point spaceshipPosition = Engine::getObjectByTag("Spaceship")->getPosition();
    camera->setPosition(Point(spaceshipPosition.x - WINDOW_WIDTH / 2, spaceshipPosition.y - WINDOW_HEIGHT / 2));
}

float Planet::getRadius() {
    return this->radius;
}

Planet::Planet(Point position): 
    Object(position, 0.f),
    Scene(new FollowCamera()) {
        this->type = this->tag = "Planet";
        this->radius = rand() % PLANET_RANGE_RADIUS + PLANET_MIN_RADIUS;
        this->entryPoint = Point(0.f, -(radius + SPACESHIP_DISTANCE_FROM_FLOOR));
        this->shape = buildShape();
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
            Point point = realDistance * Point(cos(realAngle), sin(realAngle));
            this->points.push_back(point);
        }
        for (int i = 0; i <= nPoints; i++) {
            Point start = this->points.at((i + nPoints - 1) % nPoints);
            Point end = this->points.at(i % nPoints);
            Point difference = end - start;
            Engine::instantiate(new Surface(start, difference), this);
        }
    }

void Planet::update() { }
