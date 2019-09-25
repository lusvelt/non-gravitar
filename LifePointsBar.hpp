#ifndef _LIFEPOINTSBAR_H_
#define _LIFEPOINTSBAR_H_

#include "Declarations.hpp"

#include "Object.hpp"

class LifePointsBar : public Object {
    private:
        Shape* buildShape();
        int hits;
        int requiredHits;

    public:
        void update(const float);
        LifePointsBar(int life, Vector2f, float);
        void decreasePoints();
        bool hasEnded();
};

#endif