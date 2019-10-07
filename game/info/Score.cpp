#include "Score.hpp"
#include "../../engine/Info.hpp"
#include "../../engine/Engine.hpp"
#include "../NonGravitar.hpp"


Score::Score(int score) : Info(new Text(), Point(10, 10)){
    Font *font = new Font();
    font->loadFromFile("game/info/Hyperspace.otf");
    text->setFont(*font);
    text->setFillColor(Color::White);
    text->setCharacterSize(20);
    text->setString(to_string(score));
}

void Score::update(){
    string s = "Score: ";
    s += to_string(((NonGravitar *)Engine::getGame())->getScore());
    text->setString(s);
}