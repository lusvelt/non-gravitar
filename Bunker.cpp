

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

Bunker::Bunker(Shape* shape, int lifePoints, float maxRay, float angularFactor, float bunkerCoolDown) : Object(shape, Vector2f(BUNKER_WIDTH, BUNKER_HEIGHT), 180.f) {
    this->tag = "Bunker";
    this->bunkerCoolDown = bunkerCoolDown;
    this->bunkerShootTime = 0;
    this->life = new LifePointsBar(lifePoints);
    this->maxRay = maxRay;
    this->fireAngle = 0;
    this->angularFactor = angularFactor;
}

void Bunker::onCollisionEnter(Object* collider) {
        if (collider->compareTag("Bullet")){
            this->life->decreasePoints();
        }
        
        if(this->life->controlLife()) delete this;
}

void Bunker::update(const float deltaTime) {
    if (bunkerShootTime <= 0) shoot();
    if (bunkerShootTime > 0) bunkerShootTime -= deltaTime;
}

void Bunker::shoot() {
    Vector2f versor = Vector2f(cos(fireAngle), -sin(fireAngle));
    Bullet *bullet = new Bullet(this->position + 45.f * versor, BULLET_BASE_SPEED * versor);
    this->bunkerShootTime = this->bunkerCoolDown;
    this->studyFireAngle();
}