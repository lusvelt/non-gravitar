#include "Engine.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

void Engine::initialize(Game& game) {
    Engine::window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    Engine::game = &game;
}

void Engine::run() {
    Engine::clock.restart();
    while (window->isOpen()) {
        Event event;
        while (window->pollEvent(event))
            if (event.type == Event::Closed)
                window->close();

        float deltaTime = clock.restart().asSeconds();
        Engine::currentScene->camera->update(deltaTime);
        game->update(deltaTime);
    }
}