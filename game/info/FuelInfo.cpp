#include "FuelInfo.hpp"

#include "../bunkers/LifePointsBar.hpp"

Shape* FuelInfo::buildShape() {
    return new RectangleShape(Vector(100, 10));
}

FuelInfo::FuelInfo() : Info(new LifePointsBar(100, Point(0, 0), 0), Point(50, 50)) {}

void FuelInfo::update() {
    // TODO leggere il valore attuale del fuel da Spaceship
    // aggiornando opportunamente la shape della barra (vi si può accedere mediante this->getObject()->getShape())
    // Ovviamente se il fuel è terminato è game over (astronave invisibile e immobile)
}