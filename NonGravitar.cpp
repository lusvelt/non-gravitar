#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Declarations.hpp"
#include "Game.hpp"
#include "Engine.hpp"

using namespace sf;
using namespace sf::Style;

int main() {
    Game game = Game();
    Engine::initialize(game);
    Engine::run();
}