#include "Object.hpp"

#include "Engine.hpp"

Object::Object(Shape* shape, Point position, float rotation) {
    this->shape = shape;
    this->position = position;
    this->rotation = rotation;
    this->speed = Point(0.f, 0.f);
    this->acceleration = Point(0.f, 0.f);
    this->angularSpeed = 0;
    this->tag = "Object";
    this->type = "Object";
    this->prevPointer = NULL;
    this->visible = true;
    this->deleteIfOutOfBounds = false;
}

Object::Object(Object* obj) {
    this->position = obj->position;
    this->tag = obj->tag;
    this->prevPointer = obj;
    this->visible = true;
    this->deleteIfOutOfBounds = false;
}

Object::Object(Point position, float rotation) {
    this->position = position;
    this->rotation = rotation;
    this->speed = Point(0.f, 0.f);
    this->acceleration = Point(0.f, 0.f);
    this->angularSpeed = 0;
    this->tag = "Object";
    this->type = "Object";
    this->prevPointer = NULL;
    this->visible = true;
    this->deleteIfOutOfBounds = false;
}

Object::Object(Shape* shape) {
    this->shape = shape;
    this->position = Point(0.f, 0.f);
    this->rotation = 0.f;
    this->speed = Point(0.f, 0.f);
    this->acceleration = Point(0.f, 0.f);
    this->angularSpeed = 0;
    this->tag = "Object";
    this->type = "Object";
    this->prevPointer = NULL;
    this->visible = true;
    this->deleteIfOutOfBounds = false;
}

Object::~Object() {
    while (!children.empty()) {
        Object* child = children.at(0);
        children.erase(remove(children.begin(), children.end(), child), children.end());
        delete child;
    }      
}

Shape* Object::getShape() {
    return this->shape;
}

Point Object::getPosition() {
    return this->position;
}

float Object::getPolarRadius() {
    return sqrt(pow(this->position.x, 2) + pow(this->position.y, 2));
}

float Object::getRotation() {
    return this->rotation;
}

string Object::getTag() {
    return tag;
}

bool Object::compareTag(string tag) {
    return this->tag == tag;
}

void Object::updateTransform() {
    const float deltaTime = Engine::getDeltaTime();
    
    speed += deltaTime * acceleration;
    setPosition(position + deltaTime * speed);
    setRotation(rotation + deltaTime * angularSpeed);

    shape->setPosition(position);
    shape->setRotation(rotation);
}

void Object::onCollisionEnter(Object* collider) { }

Object* Object::getPrevPointer() {
    return this->prevPointer;
}

bool Object::isAClone() {
    return this->prevPointer != NULL;
}

void Object::onBoundHit(Bound bound) { }

void Object::update() { }

void Object::setPosition(Point position) {
    Vector difference = position - this->position;
    this->position = position;
    for (int i = 0; i < children.size(); i++)
        children.at(i)->setPosition(children.at(i)->getPosition() + difference);
}

void Object::setSpeed(Point speed) {
    this->speed = speed;
}

bool Object::isOutOfBounds() {
    Point objPosition = this->position - Engine::getCurrentScene()->getCamera()->getPosition();
    Game* game = Engine::getGame();
    return objPosition.x < -game->getOutOfBoundsOffsetX() ||
           objPosition.x > game->getViewWidth() + game->getOutOfBoundsOffsetX() ||
           objPosition.y < -game->getOutOfBoundsOffsetY() ||
           objPosition.y > game->getViewHeight() + game->getOutOfBoundsOffsetY();
}

bool Object::shouldBeDeletedIfOutOfBounds() {
    return deleteIfOutOfBounds;
}

bool Object::collidesWith(Object* obj) {
    Shape* thisShape = shape;
    Shape* thatShape = obj->getShape();

    return thisShape->getGlobalBounds().intersects(thatShape->getGlobalBounds());
}

vector<Object*> Object::getChildren() {
    return children;
}

void Object::addChild(Object* obj) {
    children.push_back(obj);
    obj->setCurrentScene(this->currentScene);
}

void Object::hide() {
    visible = false;
}

void Object::show() {
    visible = true;
}

bool Object::isVisible() {
    return visible;
}

Scene* Object::getCurrentScene() {
    return currentScene;
}

void Object::setCurrentScene(Scene* scene) {
    currentScene = scene;
}

void Object::setRotation(float rotation) {
    float difference = rotation - this->rotation;
    this->rotation = rotation;
    for (int i = 0; i < children.size(); i++)
        children.at(i)->setRotation(children.at(i)->getRotation() + difference);
}

void Object::moveOf(Vector vector) {
    setPosition(position + vector);
    for (int i = 0; i < children.size(); i++)
        children.at(i)->moveOf(vector);
}

bool Object::instanceOf(string type) {
    return this->type == type;
}