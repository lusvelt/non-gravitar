#ifndef _GAME_CONTROLLER_H_
#define _GAME_CONTROLLER_H_

#include "Declarations.hpp"

#include "Scene.hpp"

class Game {
    private:
        unsigned int score;
        unsigned int fuel;
        unsigned int lives;
        vector<Scene*> scenes;

    public:
        Game();
        void update(const float deltaTime);

};

#endif