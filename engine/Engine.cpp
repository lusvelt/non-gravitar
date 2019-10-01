#include "Engine.hpp"

#include "Camera.hpp"

Clock Engine::clock;
RenderWindow *Engine::window;
Scene *Engine::currentScene = NULL;
queue<Object*> Engine::objectsQueue;
Game *Engine::game;
vector<Object*> Engine::potentialColliders;
vector<Object*> Engine::removedObjects;
Scene* Engine::preparingScene = NULL;
Scene* Engine::prevScene = NULL;
float Engine::deltaTime = 0;

void Engine::initialize(Game* game) {
    Engine::window = new RenderWindow(VideoMode(game->getViewWidth(), game->getViewHeight()), game->getTitle());
    Engine::window->setFramerateLimit(game->getFramerateLimit());
    Engine::game = game;
}

void Engine::draw(Object* obj) {
    Point objPosition = obj->getPosition();
    Point cameraPosition = Engine::currentScene->getCamera()->getPosition();
    Shape *objShape = obj->getShape();
    objShape->setPosition(Point(objPosition - cameraPosition));
    objShape->setRotation(obj->getRotation());
    Point shapePosition = objShape->getPosition();
    window->draw(*objShape);
}

void Engine::checkCollisions(Object* obj) {
    for (int i = 0; i < potentialColliders.size() && !hasJustBeenRemoved(obj); i++) {
        Object* potentialCollider = potentialColliders.at(i);
        if (obj != potentialCollider && obj->collidesWith(potentialCollider)) {
            obj->onCollisionEnter(potentialCollider);
            potentialCollider->onCollisionEnter(obj);
        }
    }
    if (!hasJustBeenRemoved(obj))
        potentialColliders.push_back(obj);
    emptyRemovedObjectsVector();
}

void Engine::checkBoundsHit(Object* obj) {
    FloatRect boundsRect = obj->getShape()->getGlobalBounds();
    Bound bound = NO_BOUND;
    if (boundsRect.left <= 0)
        bound = LEFT_BOUND;
    else if (boundsRect.top <= 0)
        bound = TOP_BOUND;
    else if (boundsRect.left + boundsRect.width >= game->getViewWidth())
        bound = RIGHT_BOUND;
    else if (boundsRect.top + boundsRect.height >= game->getViewHeight())
        bound = BOTTOM_BOUND;
    
    if (bound != NO_BOUND)
        obj->onBoundHit(bound);
}

void Engine::process(Object* obj) {
    if (!obj->isOutOfBounds()) {
        draw(obj);
        checkCollisions(obj);
        if (!hasJustBeenRemoved(obj))
            checkBoundsHit(obj);
    }
}

void Engine::run() {
    clock.restart();
    while (window->isOpen()) {
        Event event;
        while (window->pollEvent(event))
            if (event.type == Event::Closed)
                window->close();

        Engine::deltaTime = clock.restart().asSeconds();
        
        currentScene->getCamera()->update();

        window->clear(Color::Black);
        vector<Object*> *objects = currentScene->getObjects();
        for (int i = 0; i < objects->size(); i++) {
            Object* obj = objects->at(i);
            if (obj->isOutOfBounds() && obj->shouldBeDeletedIfOutOfBounds())
                destroy(obj);
            else {
                obj->update();
                obj->updateTransform();
                process(obj);
            }
        }
        potentialColliders.clear();
        window->display();
    }
}

void Engine::setCurrentScene(Scene* currentScene) {
    Engine::prevScene = Engine::currentScene;
    Engine::currentScene = currentScene;

    while (!objectsQueue.empty()) {
        currentScene->addObject(objectsQueue.front());
        objectsQueue.pop();
    }
}

Scene* Engine::getCurrentScene() {
    return currentScene;
}

void Engine::addObjectToCurrentScene(Object* obj) {
    currentScene->addObject(obj);
}

void Engine::removeObjectFromCurrentScene(Object* obj) {
    vector<Object*> *objects = currentScene->getObjects();
    objects->erase(remove(objects->begin(), objects->end(), obj), objects->end());
    potentialColliders.erase(remove(objects->begin(), objects->end(), obj), objects->end());
}

void Engine::checkAndRemoveIfOutOfBounds(Object* obj) {
    if (obj->isOutOfBounds())
        destroy(obj);
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

Object* Engine::instantiate(Object* obj) {
    currentScene->addObject(obj);
    return obj;
}

Object* Engine::instantiate(Object* obj, Scene* scene) {
    scene->addObject(obj);
    preparingScene = scene;
    return obj;
}

void Engine::emptyRemovedObjectsVector() {
    while (!removedObjects.empty()) {
        Object* obj = removedObjects.front();
        removedObjects.erase(remove(removedObjects.begin(), removedObjects.end(), obj), removedObjects.end());
        delete obj;
    }
}

Object* Engine::getObjectByTag(string tag) {
    int i = 0;
    Object* obj = NULL;
    vector<Object*> *objects = currentScene->getObjects();
    while (i < objects->size() && obj == NULL) {
        if (objects->at(i)->compareTag(tag))
            obj = objects->at(i);
        i++;
    }
    return obj;
}

Scene* Engine::getPreparingScene() {
    return preparingScene;
}

void Engine::backToPrevScene() {
    if (Engine::prevScene != NULL)
        Engine::setCurrentScene(Engine::prevScene);
}

bool Engine::isInCurrentScene(Object* obj) {
    vector<Object*> objects = *currentScene->getObjects();
    return find(objects.begin(), objects.end(), obj) != objects.end();
}

Scene* Engine::getPrevScene() {
    return prevScene;
}

void Engine::moveObjectToAnotherScene(Object* obj, Scene* scene) {
    Engine::removeObjectFromCurrentScene(obj);
    scene->addObject(obj, scene->getEntryPoint());
}

void Engine::setCurrentSceneKeepingObject(Scene* scene, Object* obj) {
    Engine::moveObjectToAnotherScene(obj, scene);
    Engine::setCurrentScene(scene);
}

float Engine::getDeltaTime() {
    return deltaTime;
}

Game* Engine::getGame() {
    return game;
}