#include "Bunker.hpp"
#include <iostream>
#include "../bullets/BunkerBullet.hpp"
#include "../../engine/Engine.hpp"
#include "../../engine/geometry/Segment.hpp"
#include "../NonGravitar.hpp"

Bunker::Bunker(Shape* shape, int lifePoints, float maxRay, float angularFactor, float bunkerCoolDown) :
    Object(shape, Point(250.f, 250.f), 0.f) {
    this->tag = "Bunker";
    this->type = "Bunker";
    this->bunkerCoolDown = bunkerCoolDown;
    this->bunkerShootTime = 0;
    this->life = new LifePointsBar(lifePoints, Point(0.f, 20.f), this->rotation);
    this->addChild(this->life);
    this->maxRay = maxRay;
    this->fireAngle = 0.f;
    this->angularFactor = angularFactor;
    this->bulletSpeed = BUNKER_BULLET_SPEED;
    this->shootPoint = Point(0,0);
}

void Bunker::onCollisionEnter(Object* collider) {
        if (collider->compareTag("SpaceshipBullet"))
                life->decreasePoints();
        
        if (life->hasEnded()){
            ((NonGravitar*) Engine::getGame())->addScore(bunkerPoints);
            this->planet->bunkerDestroyed();
            Engine::destroy(this);
        }
}

void Bunker::update() {
    if (Engine::isInCurrentScene(this)) {
        if (bunkerShootTime <= 0) shoot();
        if (bunkerShootTime > 0) bunkerShootTime -= Engine::getDeltaTime();
    }
}

void Bunker::shoot() {
    this->studyFireAngle();
    Vector versor = Vector(cos((fireAngle - rotation + 90) * M_PI / 180), -sin((fireAngle - rotation + 90) * M_PI / 180));
    BunkerBullet *bullet = (BunkerBullet*) Engine::instantiate(new BunkerBullet(this->shootPoint, this->bulletSpeed * versor));
    this->bunkerShootTime = this->bunkerCoolDown;
}

void Bunker::studyFireAngle(){ }

void Bunker::setPosition(Segment* s) {
    float l = s->getLength();
    float m = s->getM();
    float m2 = m * m;
    float x1 = s->getP1().x;
    float y1 = s->getP1().y;
    float x2 = s->getP2().x;
    float y2 = s->getP2().y;
    float xm = (x1 + x2) / 2;
    float ym = (y1 + y2) / 2;
    float norm = sqrt(xm * xm + ym * ym);
    float sg = -1;
    if (ym >= 0)
        sg = 1;

    if (((m >= 0 && ((xm < 0 && ym < 0) || (xm >= 0 && ym >= 0))) || (m < 0 && ((xm < 0 && ym >= 0) || (xm >= 0 && ym < 0)))) && abs(xm) >= norm - 100.f)
       sg *= -1;
    
    float k = (sg > 0 ? 1 : 0);
    float xb = ((m2 + 1) * (x1 + x2) + sg * 50 * sqrt(m2 + 1)) / (2 * (m2 + 1));
    float yb = s->evaluateY(xb);
    this->position = Point(xb, yb);
    this->rotation = atan(m) * 180 / M_PI + 180 * k;
    float xl = sg * 20.f * m / sqrt(m2 + 1);
    float yl = - xl / m;
    this->life->setPosition(Point(position.x + xl, position.y + yl));
    this->life->setRotation(this->rotation);
    Vector versor = Point(xm, ym) / norm;
    this->shootPoint = Point(xm, ym) + versor * 25.f;
}

void Bunker::setPlanet(Planet* planet) {
    this->planet = planet;
}