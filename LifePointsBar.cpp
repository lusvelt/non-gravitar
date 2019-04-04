#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include "LifePointsBar.hpp"

using namespace sf;
using namespace std;

Shape* LifePointsBar::buildShape(){
    RectangleShape* shape = new RectangleShape(Vector2f(MAX_LENGTH_LIFE_BARS,2.f));
    shape->setFillColor(Color::Green);

    return shape;
};

LifePointsBar::LifePointsBar(float points) : Object(LifePointsBar::buildShape(),Vector2f(BUNKER_WIDTH- 50.f, BUNKER_HEIGHT + 40.f), 0.f){
    this->maxLifePoints = 300.f; //MODIFICA QUANDO AVRAI LE SOTTOCLASSI DEI BUNKER
    this->lifePoints = 300.f;
    this->length = MAX_LENGTH_LIFE_BARS;
}

void LifePointsBar::decreasePoints(){
    this->lifePoints -= maxLifePoints/4;
    this->length -= MAX_LENGTH_LIFE_BARS/4;
    this->shape = new RectangleShape(Vector2f(this->length,2.f));
    shape->setFillColor(Color::Green);


    if(this->controlLife()) delete this;
}

bool LifePointsBar::controlLife(){
    if(this->lifePoints == 0) return true;
    else return false;
}


void LifePointsBar::update(const float deltaTime){ }

