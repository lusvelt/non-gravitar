#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include "Declarations.hpp"
#include "Game.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"

using namespace sf;

class Engine {
    private:
        static Clock clock;
        static RenderWindow *window;
        static Scene *currentScene;
        static Game *game;
        static queue<Object*> objectsQueue;
        static bool preparingScene;
        static void draw(Object*);
        static vector<Object*> potentialColliders;
        static void checkCollisions(Object*);
        static void drawAndCheckCollisions(Object*);

    public:
        static void initialize(Game&);
        static void run();
        static void setCurrentScene(Scene*);
        static Scene* getCurrentScene();
        static void addObjectToCurrentScene(Object*);
        static void removeObjectFromCurrentScene(Object*);
        static bool isOutOfBounds(Object*);
        static void checkAndRemoveIfOutOfBounds(Object*);
        static void startPreparingScene();

};

#endif