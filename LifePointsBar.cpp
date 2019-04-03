#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include "LifePointsBar.hpp"

using namespace sf;
using namespace std;

Shape* LifePointsBar::buildShape(){
    ConvexShape* shape = new ConvexShape(4);

    shape->setPoint(0, Vector2f(-50.f, -1.f));
    shape->setPoint(1, Vector2f(50.f, -1.f));
    shape->setPoint(2, Vector2f(50.f, 1.f));
    shape->setPoint(3, Vector2f(-50.f, 1.f));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(Color::Green);
    shape->setFillColor(Color::Green);

    return shape;
};

LifePointsBar::LifePointsBar(int points) : Object(LifePointsBar::buildShape(),Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 0.f){
    this->lifePoints = 300f; //MODIFICA QUANDO AVRAI LE SOTTOCLASSI DEI BUNKER
}

void decreasePointsBar(float damage){
    this->lifePoints -= damage;
}

void LifePointsBar::update(const float deltaTime){ }

