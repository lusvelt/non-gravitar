#include "Score.hpp"
#include <sstream>
#include "../../engine/Info.hpp"


Score::Score(int score) : Info(new Text(), Point(50, 50)){

    ostringstream ss;
    ss<<score;   
    this->getText()->setColor(Color::White);
    this->getText()->setCharacterSize(30);
    this->getText()->setString(ss.str());
}

void Score::update(){}