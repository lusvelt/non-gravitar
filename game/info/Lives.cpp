#include "Lives.hpp"
#include <sstream>
#include "../spaceship/Spaceship.hpp"


Lives::Lives(float lifes): Info(new Text(), Point(50,80)){

    ostringstream ss;
    ss<<lifes;
    this->getText()->setColor(Color::White);
    this->getText()->setCharacterSize(100);
    this->getText()->setString(ss.str());
}

void Lives::update(){}