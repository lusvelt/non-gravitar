#include "Bunker.hpp"

#include "../bullets/Bullet.hpp"
#include "../../engine/Engine.hpp"

Bunker::Bunker(Shape* shape, int lifePoints, float maxRay, float angularFactor, float bunkerCoolDown) :
    Object(shape, Vector2f(15.f, 55.f), 0.f) {
    this->tag = "Bunker";
    this->bunkerCoolDown = bunkerCoolDown;
    this->bunkerShootTime = 0;
    this->life = (LifePointsBar*) Engine::instantiate(new LifePointsBar(lifePoints, Vector2f(15.f, 55.f), this->getRotation()), Engine::getPreparingScene());
    this->maxRay = maxRay;
    this->fireAngle = 0.f;
    this->angularFactor = angularFactor;
    this->bulletSpeed = BULLET_BASE_SPEED;
    
}

void Bunker::onCollisionEnter(Object* collider) {
        if (collider->compareTag("Bullet")){
            if (((Bullet*) collider)->compareSourceTag("Spaceship"))
                life->decreasePoints();
        }
        
        if (life->hasEnded())
            Engine::destroy(this);
}

void Bunker::update() {
    if (Engine::isInCurrentScene(this)) {
        if (bunkerShootTime <= 0) shoot();
        if (bunkerShootTime > 0) bunkerShootTime -= Engine::getDeltaTime();
    }
}

void Bunker::shoot() {
    this->studyFireAngle();
    Point versor = Point(cos((fireAngle + 90) * M_PI / 180), -sin((fireAngle + 90) * M_PI / 180));
    Bullet *bullet = (Bullet*) Engine::instantiate(new Bullet(this->position + this->shootPoint() * versor, this->bulletSpeed * versor, tag));
    this->bunkerShootTime = this->bunkerCoolDown;
}

void Bunker::studyFireAngle(){
    this->fireAngle -= this->getRotation();
}

float Bunker::getBaseLength(){
    return this->shape->getPoint(1).x - this->shape->getPoint(0).x; 
}

Vector2f Bunker::getLPBCoordinates(){
    return this->shape->getPoint(0);
    //1 è il punto piu' a destra della base, inoltre la base non è la più larga ma quella più in basso!!!
}