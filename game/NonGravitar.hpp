#ifndef _NON_GRAVITAR_H_
#define _NON_GRAVITAR_H_

#include "config/Declarations.hpp"

#include "../engine/Game.hpp"

class NonGravitar : public Game {
    private:
        int score;

    public:
        NonGravitar();
        void addScore(int);
        int getScore();
        void generateSolarSystem();
};

#endif