#include "LifePointsBar.hpp"

#include "Engine.hpp"

Shape* LifePointsBar::buildShape(){
    RectangleShape* shape = new RectangleShape(Vector2f(50.f,2.f));
    shape->setFillColor(Color::Green);

    return shape;
};

LifePointsBar::LifePointsBar(int life, Vector2f startingPosition, float startingRotation) : Object(LifePointsBar::buildShape(), startingPosition,startingRotation){
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