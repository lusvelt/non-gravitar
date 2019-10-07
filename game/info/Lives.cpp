#include "Lives.hpp"
#include "../spaceship/Spaceship.hpp"
#include "../../engine/Engine.hpp"


Lives::Lives(int lives): Info(new Text(), Point(10, 30)){
    Font* font = new Font();
    font->loadFromFile("game/info/Hyperspace.otf");
    text->setFont(*font);
    text->setFillColor(Color::White);
    text->setCharacterSize(20);
    text->setString("");
}

void Lives::update() {
    string s = "Lives: ";
    s += to_string(((Spaceship *)Engine::getObjectByTag("Spaceship"))->getLives());
    s += "\nFuel:";
    text->setString(s);
}