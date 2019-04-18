#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include "LifePointsBar.hpp"
#include "Engine.hpp"

using namespace sf;
using namespace std;

Shape* LifePointsBar::buildShape(){
    RectangleShape* shape = new RectangleShape(Vector2f(LIFE_BARS_LENGTH,2.f));
    shape->setFillColor(Color::Green);

    return shape;
};

LifePointsBar::LifePointsBar(int life) : Object(LifePointsBar::buildShape(),Vector2f(BUNKER_WIDTH - 50.f, BUNKER_HEIGHT + 40.f), 0.f){
    this->length = LIFE_BARS_LENGTH;
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