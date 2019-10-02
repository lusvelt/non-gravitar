#include "Fuel.hpp"
#include "../../engine/Object.hpp"
#include "../../engine/Engine.hpp"


Fuel::Fuel(Shape* shape):
Object(shape, position, rotation){
    this->tag= "Fuel";
}

void Fuel::update(){ }