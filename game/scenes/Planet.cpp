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
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 255);
    shape->setFillColor(Color(dis(gen), dis(gen), dis(gen)));
    shape->setOutlineThickness((rand()%2)+1);
    shape->setOutlineColor(Color(dis(gen), dis(gen), dis(gen)));
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
    int nPoints = 2 * M_PI * (float)radius / PIXELS_PER_POINT;
    int rangeX = PIXELS_PER_POINT / 2 * PLANET_POINT_RANGE_SCALE_X;
    int rangeY = PIXELS_PER_POINT / 2 * PLANET_POINT_RANGE_SCALE_Y;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> disX(-rangeX / 2, rangeX / 2);
    uniform_int_distribution<> disY(-rangeY / 2, rangeY / 2);
    uniform_int_distribution<> disB(1, 100);
    uniform_int_distribution<> disT(0, 3);
    for (int i = 0; i < nPoints; i++) {
        int offsetX = disX(gen);
        int offsetY = disY(gen);
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
        populateSegment(segment, disB(gen), disT(gen));
    }
}

void Planet::populateSegment(Segment* segment, int rand, int type) {
    Bunker* bunker = NULL;
    Fuel* fuel = NULL;
    if (rand < SMALL_FUEL_LIKELYHOOD) {
        fuel = new SmallFuel();
    } else if (rand < SMALL_FUEL_LIKELYHOOD + BIG_FUEL_LIKELYHOOD) {
        fuel = new BigFuel();
    } else if (rand < SMALL_FUEL_LIKELYHOOD + BIG_FUEL_LIKELYHOOD + BUNKER_LIKELYHOOD) {
        if (type == 0) bunker = new TankBunker();
        else if (type == 1) bunker = new DoubleShootBunker();
        else if (type == 2) bunker = new TwoDirectionBunker();
        else bunker = new ThreeDirectionBunker();
        bunkerCount++;
    }
    if (bunker != NULL) {
        bunker->setPosition(segment);
        bunker->setPlanet(this);
        Engine::instantiate(bunker, this);
    }
    if (fuel != NULL) {
        fuel->setPosition(segment);
        Engine::instantiate(fuel, this);
    }
}

Planet::Planet(Point position, int radius) : Object(position, 0.f),
                                 Scene(new FollowCamera()) {
        this->sceneType = this->tag = "Planet";
        this->radius = radius;
        this->entryPoint = Point(0.f, -(radius + SPACESHIP_DISTANCE_FROM_FLOOR));
        this->shape = buildShape();
        bunkerCount = 0;
        buildSurface();
    }

void Planet::update() { }

void Planet::bunkerDestroyed() {
    bunkerCount--;
}

bool Planet::hasNoBunkers() {
    return bunkerCount == 0;
}