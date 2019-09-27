#include "engine/Engine.hpp"
#include "game/NonGravitar.hpp"
#include "engine/Game.hpp"

int main() {
    Engine::initialize(new NonGravitar());
    Engine::run();
}