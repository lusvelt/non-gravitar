#include "Spaceship.hpp"

#include "../bullets/SpaceshipBullet.hpp"
#include "../../engine/Engine.hpp"
#include "../scenes/Planet.hpp"

Shape* Spaceship::buildShape() {
    ConvexShape* shape = new ConvexShape(6);

    shape->setPoint(0, Point(-4.f, 0.f));
    shape->setPoint(1, Point(-8.f, 4.f));
    shape->setPoint(2, Point(0.f, 12.f));
    shape->setPoint(3, Point(16.f, 0.f));
    shape->setPoint(4, Point(0.f, -12.f));
    shape->setPoint(5, Point(-8.f, -4.f));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Blue);
    shape->setFillColor(Color::Black);
    shape->setScale(SPACESHIP_SCALE, SPACESHIP_SCALE);

    return shape;
}

Spaceship::Spaceship():
    Object(Spaceship::buildShape()) {
    this->lifes = 5;
    this->shootCd = 0;
    this->tag = "Spaceship";
}

void Spaceship::resetAccelerationAndAngularSpeed() {
    acceleration.x = 0.f;
    acceleration.y = 0.f;
    angularSpeed = 0.f;
}

void Spaceship::accelerateForward() {
    acceleration.x = ACCELERATION_MODULE * cos(rotation * M_PI / 180);
    acceleration.y = ACCELERATION_MODULE * sin(rotation * M_PI / 180);
}

void Spaceship::accelerateBackward() {
    acceleration.x = -ACCELERATION_MODULE * cos(rotation * M_PI / 180);
    acceleration.y = -ACCELERATION_MODULE * sin(rotation * M_PI / 180);
}

void Spaceship::rotateLeft() {
    angularSpeed = -ANGULAR_SPEED_MODULE;
}

void Spaceship::rotateRight() {
    angularSpeed = ANGULAR_SPEED_MODULE;
}

void Spaceship::update() {
    resetAccelerationAndAngularSpeed();
    if(this->lifes > 0){
        if (Keyboard::isKeyPressed(Keyboard::Up))
            accelerateForward();
        if (Keyboard::isKeyPressed(Keyboard::Down))
            accelerateBackward();
        if (Keyboard::isKeyPressed(Keyboard::Left))
            rotateLeft();
        if (Keyboard::isKeyPressed(Keyboard::Right))
            rotateRight();
        if (Keyboard::isKeyPressed(Keyboard::Space) && shootCd <= 0)
            shoot();

        if (this->isOutOfRadius())
            this->backToPrevScene();
    }
    if (shootCd > 0)
        shootCd -= Engine::getDeltaTime();
}

void Spaceship::shoot() {
    Point versor = Point(cos(this->rotation * M_PI / 180), sin(this->rotation * M_PI / 180));
    Point position = this->position + BULLET_DISTANCE_RADIUS * versor;
    Point speed = this->speed + BULLET_BASE_SPEED * versor;
    Engine::instantiate(new SpaceshipBullet(position, speed));
    this->shootCd = SPACESHIP_SHOOT_COOLDOWN;
}

void Spaceship::onBoundHit(Bound bound) {
    if (bound == LEFT_BOUND || bound == RIGHT_BOUND)
        speed = Point(-speed.x, speed.y);
    else if (bound == TOP_BOUND || bound == BOTTOM_BOUND)
        speed = Point(speed.x, -speed.y);
}

bool Spaceship::isOutOfRadius() {
    return Engine::getCurrentScene()->compareType("Planet") && this->getPolarRadius() > ((Planet*) Engine::getCurrentScene())->getRadius() + PLANET_ATMOSPHERE_HEIGHT;
}

void Spaceship::backToPrevScene() {
    Engine::moveObjectToAnotherScene(this, Engine::getPrevScene());
    Engine::backToPrevScene();
}

void Spaceship::onCollisionEnter(Object* obj) {
    if (obj->instanceOf("Bunker") || obj->compareTag("BunkerBullet") || obj->compareTag("Surface")) {
        if(this->lifes > 0){
            this->lifes--;
            Engine::moveObjectToAnotherScene(this, Engine::getCurrentScene());
        }
        // TODO diminuire una vita e ripartire dall'entryPoint del pianeta, se le vite sono finite rendere invisibile e immanovrabile la spaceship
    }
}

int Spaceship::getLife(){
    return this->lifes;
}

void Spaceship::getFuel(int newFuel){
    this->totalFuel += newFuel;
}