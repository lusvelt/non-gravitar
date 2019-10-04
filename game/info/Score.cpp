#include "Score.hpp"
#include "../../engine/Info.hpp"


Score::Score() : Info(new Text(), Point(50, 50)){

    this->getText()->setString("prova");
    this->getText()->setColor(Color::White);
    this->getText()->setCharacterSize(30);
}

void Score::update(){}