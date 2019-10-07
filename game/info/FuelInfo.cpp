#include "FuelInfo.hpp"

#include "FuelBar.hpp"
#include "../spaceship/Spaceship.hpp"
#include "../../engine/Engine.hpp"

Shape* FuelInfo::buildShape() {
    return new RectangleShape(Vector(100, 10));
}

FuelInfo::FuelInfo() : Info(new FuelBar(), Point(10, 90)) {}

void FuelInfo::update() {
    int fuel = ((Spaceship*) Engine::getObjectByTag("Spaceship"))->getFuel();
    object->getShape()->setScale(Vector((float)fuel / MAX_FUEL, 1));
    object->getShape()->setFillColor(Color(255 - 255 * fuel / MAX_FUEL, 255 * fuel / MAX_FUEL, 0));
    // TODO leggere il valore attuale del fuel da Spaceship
    // aggiornando opportunamente la shape della barra (vi si può accedere mediante this->getObject()->getShape())
    // Ovviamente se il fuel è terminato è game over (astronave invisibile e immobile)
}