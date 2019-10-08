#include "GameOver.hpp"

GameOver::GameOver() : Info(new Text(), Point(160, WINDOW_HEIGHT / 2 - 40)) {
    Font *font = new Font();
    font->loadFromFile("game/info/Hyperspace.otf");
    text->setFont(*font);
    text->setFillColor(Color::Red);
    text->setCharacterSize(80);
    text->setString("Game Over");
}