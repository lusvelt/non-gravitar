#ifndef _TANK_BUNKER_H
#define _TANK_BUNKER_H

#include "Declarations.hpp"

#include "Bunker.hpp"

class Bunker;

class TankBunker : public Bunker {
    private:
        Shape* buildShape();
    public:
        TankBunker();
        float shootPoint();
        void studyFireAngle();
};


#endif