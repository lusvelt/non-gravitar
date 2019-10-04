#include "Planet.hpp"

#include "../../engine/Object.hpp"
#include "../../engine/Scene.hpp"
#include "../../engine/Engine.hpp"
#include "../cameras/FollowCamera.hpp"
#include "../scenes/Surface.hpp"
#include "../bunkers/Bunker.hpp"
#include "../bunkers/DoubleShootBunker.hpp"
#include "../bunkers/CleverBunker.hpp"
#include "../bunkers/TwoDirectionBunker.hpp"
#include "../bunkers/ThreeDirectionBunker.hpp"
#include "../bunkers/TankBunker.hpp"
#include "../bullets/BunkerBullet.hpp"
#include "../fuel/SmallFuel.hpp"
#include "../fuel/BigFuel.hpp"

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

float Planet::getRadius() {
    return this->radius;
}

void Planet::buildSurface() {
    srand(time(NULL));
    int nPoints = 2 * M_PI * (float)radius / PIXELS_PER_POINT;
    int rangeX = PIXELS_PER_POINT / 2 * PLANET_POINT_RANGE_SCALE_X;
    int rangeY = PIXELS_PER_POINT / 2 * PLANET_POINT_RANGE_SCALE_Y;
    for (int i = 0; i < nPoints; i++) {
        int offsetX = rand() % rangeX - rangeX / 2;
        int offsetY = rand() % rangeY - rangeY / 2;
        float offsetAngle = offsetX / radius;
        float offsetDistance = offsetY;
        float currentAngle = (float)i * 2 * M_PI / nPoints;
        float realAngle = currentAngle + offsetAngle;
        float realDistance = radius + offsetDistance;
        Point point = realDistance * Point(cos(realAngle), sin(realAngle));
        this->points.push_back(point);
    }
    for (int i = 0; i <= nPoints; i++) {
        Point start = this->points.at((i + nPoints - 1) % nPoints);
        Point end = this->points.at(i % nPoints);
        Point difference = end - start;
        Surface *surface = new Surface(start, difference);
        surfaces.push_back(surface);
        Engine::instantiate(surface, this);
    }
    for (int i = 0; i < nPoints; i++) {
        Segment* segment = surfaces.at(i)->getSegment();
        populateSegment(segment);
    }
}

void Planet::populateSegment(Segment* segment) {
    int r = rand() % 100 + 1;
    Bunker* bunker = NULL;
    Fuel* fuel = NULL;
    if (r < SMALL_FUEL_LIKELYHOOD) {
        fuel = new SmallFuel();
    } else if (r < SMALL_FUEL_LIKELYHOOD + BIG_FUEL_LIKELYHOOD) {
        fuel = new BigFuel();
    } else if (r < SMALL_FUEL_LIKELYHOOD + BIG_FUEL_LIKELYHOOD + BUNKER_LIKELYHOOD) {
        int t = rand() % 5;
        if (t == 0) bunker = new TankBunker();
        else if (t == 1) bunker = new DoubleShootBunker();
        else if (t == 2) bunker = new CleverBunker();
        else if (t == 3) bunker = new TwoDirectionBunker();
        else bunker = new ThreeDirectionBunker();
    }
    if (bunker != NULL) {
        bunker->setPosition(segment);
        Engine::instantiate(bunker, this);
    }
    if (fuel != NULL) {
        fuel->setPosition(segment);
        Engine::instantiate(fuel, this);
    }
}

Planet::Planet(Point position) : Object(position, 0.f),
                                 Scene(new FollowCamera()) {
        this->sceneType = this->tag = "Planet";
        this->radius = rand() % PLANET_RANGE_RADIUS + PLANET_MIN_RADIUS;
        this->entryPoint = Point(0.f, -(radius + SPACESHIP_DISTANCE_FROM_FLOOR));
        this->shape = buildShape();
        buildSurface();
    }

void Planet::update() { }
