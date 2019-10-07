#include "Lives.hpp"
#include "../spaceship/Spaceship.hpp"
#include "../../engine/Engine.hpp"


Lives::Lives(int lives): Info(new Text(), Point(50, 80)){
    Font* font = new Font();
    font->loadFromFile("game/info/Hyperspace.otf");
    text->setFont(*font);
    text->setFillColor(Color::White);
    text->setCharacterSize(20);
    text->setString(to_string(lives));
}

void Lives::update() {
    text->setString(to_string(((Spaceship*)Engine::getObjectByTag("Spaceship"))->getLives()));
}