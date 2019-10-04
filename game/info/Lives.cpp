#include "Lives.hpp"

Lives::Lives(): Info(new Text(), Point(50,80)){

    this->getText()->setString("prova2");
    this->getText()->setColor(Color::White);
    this->getText()->setCharacterSize(100);
}

void Lives::update(){}