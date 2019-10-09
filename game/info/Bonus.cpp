#include "Bonus.hpp"

#include "../../engine/Engine.hpp"

Bonus::Bonus() : Info(new Text(), Point(WINDOW_WIDTH - 100, 10)) {
    Font *font = new Font();
    font->loadFromFile("game/info/Hyperspace.otf");
    text->setFont(*font);
    text->setFillColor(Color::White);
    text->setCharacterSize(20);
    text->setString("");
}

void Bonus::update() {
    if (Engine::getCurrentScene()->getType() == "Planet") {
        string s = "Bonus:\n";
        s += to_string(((Planet*) Engine::getCurrentScene())->getScore());
        text->setString(s);
    } else text->setString("");
}