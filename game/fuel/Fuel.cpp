#include "Fuel.hpp"
#include "../../engine/Object.hpp"
//#include "../engine/geometry/Segment.hpp"
#include "../../engine/Engine.hpp"


Fuel::Fuel(Shape* shape):
Object(shape){
    this->tag= "Fuel";
}

/*void Fuel::setPosition(Segment* s){
    Point position= calcolare la posizione in base all'origine (0,0)
    this->position=position;
} */

void Fuel::update(){ }