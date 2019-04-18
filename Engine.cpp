#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Engine.hpp"
#include "Object.hpp"

using namespace sf;
using namespace std;

Clock Engine::clock;
RenderWindow *Engine::window;
Scene *Engine::currentScene = NULL;
bool Engine::preparingScene = false;
queue<Object*> Engine::objectsQueue;
Game *Engine::game;
vector<Object*> Engine::potentialColliders;
vector<Object*> Engine::removedObjects;

void Engine::initialize(Game& game) {
    Engine::window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    Engine::game = &game;
}

void Engine::draw(Object* obj) {
    Vector2f objPosition = obj->getPosition();
    Vector2f cameraPosition = Engine::currentScene->getCamera()->getPosition();
    Shape *objShape = obj->getShape();
    objShape->setPosition(Vector2f(objPosition - cameraPosition));
    objShape->setRotation(obj->getRotation());
    Vector2f shapePosition = objShape->getPosition();
    window->draw(*objShape);
}

void Engine::checkCollisions(Object* obj) {
    for (int i = 0; i < potentialColliders.size() && !hasJustBeenRemoved(obj); i++) {
        Object* potentialCollider = potentialColliders.at(i);
        if (obj != potentialCollider && obj->getShape()->getGlobalBounds().intersects(potentialCollider->getShape()->getGlobalBounds())) {
            obj->onCollisionEnter(potentialCollider);
            potentialCollider->onCollisionEnter(obj);
        }
    }
    if (!hasJustBeenRemoved(obj))
        potentialColliders.push_back(obj);
    emptyRemovedObjectsVector();
}

void Engine::drawAndCheckCollisions(Object* obj) {
    if (!Engine::isOutOfBounds(obj)) {
        Engine::draw(obj);
        Engine::checkCollisions(obj);
    }
} 

void Engine::run() {
    clock.restart();
    while (window->isOpen()) {
        Event event;
        while (window->pollEvent(event))
            if (event.type == Event::Closed)
                window->close();

        float deltaTime = clock.restart().asSeconds();
        
        game->update(deltaTime);
        currentScene->getCamera()->update(deltaTime);

        window->clear(Color::Black);
        vector<Object*> *objects = currentScene->getObjects();
        for (int i = 0; i < objects->size(); i++) {
            Object* obj = objects->at(i);
            obj->update(deltaTime);
            obj->updateTransform(deltaTime);
            drawAndCheckCollisions(obj);
        }
        potentialColliders.clear();
        window->display();
    }
}

void Engine::setCurrentScene(Scene* currentScene) {
    Engine::currentScene = currentScene;
    preparingScene = false;
    while (!objectsQueue.empty()) {
        currentScene->addObject(objectsQueue.front());
        objectsQueue.pop();
    }
}

Scene* Engine::getCurrentScene() {
    return currentScene;
}

void Engine::addObjectToCurrentScene(Object* obj) {
    if (!preparingScene)
        currentScene->addObject(obj);
    else
        objectsQueue.push(obj);
}

void Engine::removeObjectFromCurrentScene(Object* obj) {
    vector<Object *> *objects = currentScene->getObjects();
    objects->erase(remove(objects->begin(), objects->end(), obj), objects->end());
    potentialColliders.erase(remove(objects->begin(), objects->end(), obj), objects->end());
}

bool Engine::isOutOfBounds(Object* obj) {
    Vector2f objPosition = obj->getPosition() - currentScene->getCamera()->getPosition();
    return objPosition.x < -OUT_OF_BOUNDS_OFFSET_X ||
           objPosition.x > WINDOW_WIDTH + OUT_OF_BOUNDS_OFFSET_X ||
           objPosition.y < -OUT_OF_BOUNDS_OFFSET_Y ||
           objPosition.y > WINDOW_HEIGHT + OUT_OF_BOUNDS_OFFSET_Y;
}

void Engine::checkAndRemoveIfOutOfBounds(Object* obj) {
    if (isOutOfBounds(obj))
        destroy(obj);
}

void Engine::startPreparingScene() {
    preparingScene = true;
}

bool Engine::hasJustBeenRemoved(Object* obj) {
    return find(removedObjects.begin(), removedObjects.end(), obj) != removedObjects.end();
}

void Engine::destroy(Object* obj) {
    if (!obj->isAClone()) {
        removedObjects.push_back(obj);
        removeObjectFromCurrentScene(obj);
    }
}

void Engine::emptyRemovedObjectsVector() {
    while (!removedObjects.empty()) {
        Object* obj = removedObjects.front();
        removedObjects.erase(remove(removedObjects.begin(), removedObjects.end(), obj), removedObjects.end());
        delete obj;
    }
}