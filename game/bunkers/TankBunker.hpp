#ifndef _TANK_BUNKER_H_
#define _TANK_BUNKER_H_

#include "../config/Declarations.hpp"

#include "Bunker.hpp"

class Bunker;

class TankBunker : public Bunker {
    private:
        Shape* buildShape();
    public:
        TankBunker();
        void studyFireAngle();
};


#endif