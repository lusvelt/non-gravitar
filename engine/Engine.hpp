#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Config.hpp"

#include "Scene.hpp"
#include "Game.hpp"
#include "Object.hpp"

class Game;

class Engine {
    private:
        static Clock clock;
        static RenderWindow *window;
        static Scene *currentScene;
        static Game *game;
        static queue<Object*> objectsQueue;
        static float deltaTime;
        static void draw(Object*);
        static vector<Object*> potentialColliders;
        static void checkCollisions(Object*);
        static void checkBoundsHit(Object*);
        static void process(Object*);
        static vector<Object*> removedObjects;
        static bool hasJustBeenRemoved(Object*);
        static void emptyRemovedObjectsVector();
        static Scene* preparingScene;
        static Scene* prevScene;
        static void scanAndProcessObjects(vector<Object*>);

    public:
        static void initialize(Game*);
        static void run();
        static void setCurrentScene(Scene*);
        static Scene* getCurrentScene();
        static void addObjectToCurrentScene(Object*);
        static void removeObjectFromCurrentScene(Object*);
        static void checkAndRemoveIfOutOfBounds(Object*);
        static void startPreparingScene();
        static Object* instantiate(Object*);
        static Object* instantiate(Object*, Scene*);
        static void destroy(Object*);
        static Object* getObjectByTag(string);
        static Scene* getPreparingScene();
        static bool isInCurrentScene(Object*);
        static void backToPrevScene();
        static Scene* getPrevScene();
        static void moveObjectToAnotherScene(Object*, Scene*);
        static void moveObjectsToAnotherScene(vector<Object*>, Scene*);
        static void setCurrentSceneKeepingObject(Scene*, Object*);
        static void backToPrevSceneKeepingObject(Object*);
        static float getDeltaTime();
        static Game* getGame();
};

#endif