#ifndef _LIFE_POINTS_BAR_H_
#define _LIFE_POINTS_BAR_H_

#include "../config/Declarations.hpp"

#include "../../engine/Object.hpp"

class LifePointsBar : public Object {
    private:
        Shape* buildShape();
        int hits;
        int requiredHits;

    public:
        void update();
        LifePointsBar(int life, Point, float);
        void decreasePoints();
        bool hasEnded();
};

#endif