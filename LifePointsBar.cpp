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

LifePointsBar::LifePointsBar() : Object(LifePointsBar::buildShape(),Vector2f(BUNKER_WIDTH - 50.f, BUNKER_HEIGHT + 40.f), 0.f){
    this->length = MAX_LENGTH_LIFE_BARS;
    this->hit = 0;
}

void LifePointsBar::decreasePoints(){
    
    this->shape->setScale((1-1/NUM_COLPI-hit/NUM_COLPI),1.f);
    this->hit++;
    if(this->controlLife()) delete this;
}

bool LifePointsBar::controlLife(){
    if(this->hit == NUM_COLPI) return true;
    else return false;
}


void LifePointsBar::update(const float deltaTime){ }

