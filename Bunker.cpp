#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"


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

Bunker::Bunker() : Object(Bunker::buildShape(), Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 35.f), 180.f) {
    this->tag = "Bunker";
    this->bunkerShootTime = 0;
    this->lifePoints = 300;
    this->maxLifePoints = 300;
}

void Bunker::onCollisionEnter(Object* collider) {
    if (collider->compareTag("Bullet"))
        lifePoints -= maxLifePoints/4;
        if(lifePoints <= 0) delete this;


}

/*void Bunker::shoot() {
    Vector2f versor = Vector2f(cos(this->rotation * M_PI / 180), sin(this->rotation * M_PI / 180));
    Bullet *bullet = new Bullet(this->position + 10.f * versor, this->speed + BULLET_BASE_SPEED * versor);
}
*/
void Bunker::update(const float deltaTime) {
   /* if (bunkerShootTime <= 0) shoot();
    if (bunkerShootTime > 0)
        bunkerShootTime -= deltaTime;*/
}
