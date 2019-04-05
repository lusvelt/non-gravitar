#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include "LifePointsBar.hpp"
//#include <iostream>


using namespace sf;
using namespace std;

Shape* LifePointsBar::buildShape(){
    RectangleShape* shape = new RectangleShape(Vector2f(LIFE_BARS_LENGTH,2.f));
    shape->setFillColor(Color::Green);

    return shape;
};

LifePointsBar::LifePointsBar(float life) : Object(LifePointsBar::buildShape(),Vector2f(BUNKER_WIDTH - 50.f, BUNKER_HEIGHT + 40.f), 0.f){
    this->length = LIFE_BARS_LENGTH;
    this->hit = 0;
    this->requiredHit = life;
    this->tag = "lifePointsBar";
}

void LifePointsBar::decreasePoints(){
    this->shape->setScale(1-1/(this->requiredHit)-hit/(this->requiredHit),1.f);
    this->hit++;
    if(this->controlLife()) delete this;
}

bool LifePointsBar::controlLife(){
    if(this->hit == this->requiredHit) return true;
    else return false;
}


void LifePointsBar::update(const float deltaTime){ }

