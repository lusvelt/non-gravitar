#ifndef _NON_GRAVITAR_H_
#define _NON_GRAVITAR_H_

#include "config/Declarations.hpp"

#include "../engine/Game.hpp"

class NonGravitar : public Game {
    private:
        unsigned int score;
        unsigned int fuel;
        unsigned int lives;
        int lifes;

    public:
        NonGravitar();
};

#endif