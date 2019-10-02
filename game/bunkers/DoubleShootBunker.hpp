#ifndef _DOUBLE_SHOOT_BUNKER_H
#define _DOUBLE_SHOOT_BUNKER_H

#include "../config/Declarations.hpp"

#include "Bunker.hpp"

class DoubleShootBunker : public Bunker{
    private:
        Shape* buildShape();
        int direction;
        float absFireAngle;
        int shot;

    public:
        DoubleShootBunker();
        Point shootPoint();
        void studyFireAngle();
};


#endif