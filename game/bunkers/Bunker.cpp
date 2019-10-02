#include "Bunker.hpp"

#include "../bullets/BunkerBullet.hpp"
#include "../../engine/Engine.hpp"
#include "../../engine/geometry/Segment.hpp"

Bunker::Bunker(Shape* shape, int lifePoints, float maxRay, float angularFactor, float bunkerCoolDown) :
    Object(shape, Point(250.f, 250.f), 0.f) {
    this->tag = "Bunker";
    this->bunkerCoolDown = bunkerCoolDown;
    this->bunkerShootTime = 0;
    this->life = (LifePointsBar*) Engine::instantiate(new LifePointsBar(lifePoints, Point(this->getLPBCoordinates().x, this->getLPBCoordinates().y + 20.f), this->getRotation()), Engine::getPreparingScene());
    this->maxRay = maxRay;
    this->fireAngle = 0.f;
    this->angularFactor = angularFactor;
    this->bulletSpeed = BULLET_BASE_SPEED;
    
}

void Bunker::onCollisionEnter(Object* collider) {
        if (collider->compareTag("SpaceshipBullet"))
                life->decreasePoints();
        
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
    Bullet *bullet = (Bullet*) Engine::instantiate(new Bullet(this->position + this->shootPoint(), this->bulletSpeed * versor, tag));
    this->bunkerShootTime = this->bunkerCoolDown;
}

void Bunker::studyFireAngle(){
    this->fireAngle -= this->getRotation();
}

float Bunker::getBaseLength(){
    return this->shape->getPoint(1).x - this->shape->getPoint(0).x; 
}

Point Bunker::getLPBCoordinates(){
    return this->position + this->shape->getPoint(0);
    //1 è il punto piu' a destra della base, inoltre la base non è la più larga ma quella più in basso!!!
}

void Bunker::setPosition(Segment s) {
    //float m = s.getM(); coefficiente angolare segmento s
    this->position = Point((s.getP1().x + s.getP2().x)/2 + 25.f, (s.getP1().y + s.getP2().y)/2);
    this->rotation = atan(s.getM());
}