#include "Fuel.hpp"
#include "../../engine/Object.hpp"
#include "../../engine/Engine.hpp"


Fuel::Fuel(Shape* shape):
Object(shape){
    this->tag= "Fuel";
}

void Fuel::update(){ }