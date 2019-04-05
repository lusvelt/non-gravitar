#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"

using namespace sf;
using namespace std;

Shape* Bunker::buildShape(){
    ConvexShape* shape = new ConvexShape(8);

    shape->setPoint(0, Vector2f(-50.f, -30.f));
    shape->setPoint(1, Vector2f(-30.f, 5.f));
    shape->setPoint(2, Vector2f(-10.f, 10.f));
    shape->setPoint(3, Vector2f(-10.f, 30.f));
    shape->setPoint(4, Vector2f(10.f, 30.f));
    shape->setPoint(5, Vector2f(10.f, 10.f));
    shape->setPoint(6, Vector2f(30.f, 5.f));
    shape->setPoint(7, Vector2f(50.f, -30.f));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Green);
    shape->setFillColor(Color::Black);

    return shape;
};

Bunker::Bunker() : Object(Bunker::buildShape(), Vector2f(BUNKER_WIDTH, BUNKER_HEIGHT), 180.f) {
    this->tag = "Bunker";
    this->bunkerCoolDown = 0.33f;
    this->bunkerShootTime = 0;
    this->life = new LifePointsBar(10.f);
    this->orario = true;
    this->maxRay = 0.80f;
    this->fireAngle = -maxRay;
    this->angularFactor = 0.10f;
}

void Bunker::onCollisionEnter(Object* collider) {
        if (collider->compareTag("Bullet")){
            this->life->decreasePoints();
        }
        
        if(this->life->controlLife()) delete this;
}

void Bunker::studyFireAngle(){
    if(orario){
        fireAngle += angularFactor;
        if(fireAngle >= this->maxRay) orario = false;
    }else{
        fireAngle -= angularFactor;
        if(fireAngle <= -this->maxRay) orario = true;
    }
}

void Bunker::shoot() {
    Vector2f versor = Vector2f(fireAngle, -1);
    Bullet *bullet = new Bullet(this->position + 45.f * versor, BULLET_BASE_SPEED * versor);
    this->bunkerShootTime = this->bunkerCoolDown;
    this->studyFireAngle();
}

void Bunker::update(const float deltaTime) {
    if (bunkerShootTime <= 0) shoot();
    if (bunkerShootTime > 0) bunkerShootTime -= deltaTime;
}
