#include "Declarations.hpp"
#include "Game.hpp"
#include "Engine.hpp"

int main() {
    Game game = Game();
    Engine::initialize(game);
    Engine::run();
}