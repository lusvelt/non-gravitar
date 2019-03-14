#ifndef _GAME_CONTROLLER_H_
#define _GAME_CONTROLLER_H_

#include "Spaceship.hpp"

class GameController {
    private:
        static Clock clock;
        static Time deltaTime;
        unsigned int score;
        unsigned int fuel;
        unsigned int lives;
        RenderWindow *window;
        Spaceship spaceship;

        static void setDeltaTime();

    public:
        GameController(RenderWindow&);
        void run();
        static Time getDeltaTime();

};

#endif