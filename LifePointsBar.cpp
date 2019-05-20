#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include "LifePointsBar.hpp"
#include "Engine.hpp"
#include "Bunker.hpp"

using namespace sf;
using namespace std;

Shape* LifePointsBar::buildShape(){
    RectangleShape* shape = new RectangleShape(Vector2f(this->bunkerPointer->getBaseLength(),2.f));
    shape->setFillColor(Color::Green);

    return shape;
};

LifePointsBar::LifePointsBar(int life, Bunker* bunker) : Object(LifePointsBar::buildShape(),Vector2f(this->bunkerPointer->getLPBCoordinates().x, this->bunkerPointer->getLPBCoordinates().y + 40.f), this->bunkerPointer->getRotation()){
    this->bunkerPointer = bunker;
    this->hits = 0;
    this->requiredHits = life;
    this->tag = "LifePointsBar";
}

void LifePointsBar::decreasePoints(){
    this->shape->setScale(1-1/(float)(this->requiredHits)-hits/(float)(this->requiredHits),1.f);
    this->hits++;
    if (this->hasEnded())
        Engine::destroy(this);
}

bool LifePointsBar::hasEnded(){
    if (this->hits >= this->requiredHits) return true;
    else return false;
}


void LifePointsBar::update(const float deltaTime){ }