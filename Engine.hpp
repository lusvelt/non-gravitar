#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Declarations.hpp"
#include "Game.hpp"
#include "Scene.hpp"
#include "Camera.hpp"

using namespace sf;

class Engine {
    private:
        static Clock clock;
        static RenderWindow *window;
        static Scene *currentScene;
        static Camera *camera;
        static Game *game;

    public:
        static void initialize(Game&);
        static void run();
};

#endif