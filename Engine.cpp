#include <SFML/Graphics.hpp>
#include "Engine.hpp"

using namespace sf;

Clock Engine::clock;
RenderWindow *Engine::window;
Scene *Engine::currentScene;
Camera *Engine::camera;
Game *Engine::game;

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
        
        game->update(deltaTime);
        Camera* currentCamera = Engine::currentScene->getCamera();
        currentCamera->update(deltaTime);
        Vector2f cameraPosition = currentCamera->getPosition();

        window->clear(Color::Black);
        vector<Object*> *objects = Engine::currentScene->getObjects();
        for (vector<Object*>::iterator obj = objects->begin(); obj != objects->end(); ++obj) {
            Vector2f objPosition = (*obj)->getPosition();
            (*obj)->update(deltaTime);
            Shape* objShape = (*obj)->getShape();
            objShape->setPosition(Vector2f(objPosition - cameraPosition));
            objShape->setRotation((*obj)->getRotation());
            Vector2f shapePosition = objShape->getPosition();
            window->draw(*objShape);
        }
        window->display();
    }
}

void Engine::setCurrentScene(Scene* currentScene) {
    Engine::currentScene = currentScene;
}

Scene* Engine::getCurrentScene() {
    return Engine::currentScene;
}