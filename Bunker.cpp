

#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"
#include "Engine.hpp"

using namespace sf;
using namespace std;

Bunker::Bunker(Shape* shape, int lifePoints, float maxRay, float angularFactor, float bunkerCoolDown) :
    Object(shape, Vector2f(BUNKER_WIDTH, BUNKER_HEIGHT), 0.f) {
    this->tag = "Bunker";
    this->bunkerCoolDown = bunkerCoolDown;
    this->bunkerShootTime = 0;
    this->life = (LifePointsBar*) Engine::instantiate(new LifePointsBar(lifePoints), Engine::getPreparingScene());
    this->maxRay = maxRay;
    this->fireAngle = 0.f;
    this->angularFactor = angularFactor;
    this->bulletSpeed = BULLET_BASE_SPEED;
    this->setFireAngleByRotation();
}

void Bunker::onCollisionEnter(Object* collider) {
        if (collider->compareTag("Bullet")){
            if (((Bullet*) collider)->compareSourceTag("Spaceship"))
                life->decreasePoints();
        }
        
        if (life->hasEnded())
            Engine::destroy(this);
}

void Bunker::update(const float deltaTime) {
    if (Engine::isInCurrentScene(this)) {
        if (bunkerShootTime <= 0) shoot();
        if (bunkerShootTime > 0) bunkerShootTime -= deltaTime;
    }
}

void Bunker::shoot() {
    Vector2f versor = Vector2f(cos((fireAngle + 90) * M_PI / 180), -sin((fireAngle + 90) * M_PI / 180));
    Bullet *bullet = (Bullet*) Engine::instantiate(new Bullet(this->position + this->shootPoint() * versor, this->bulletSpeed * versor, tag));
    this->bunkerShootTime = this->bunkerCoolDown;
    this->studyFireAngle();
}

void Bunker::setFireAngleByRotation(){
    this->fireAngle -= this->getRotation();
}