#ifndef _LIFEPOINTSBAR_H_
#define _LIFEPOINTSBAR_H_

#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include "Object.hpp"
#include "Bunker.hpp"

using namespace sf;
using namespace std;

class LifePointsBar : public Object {
    private:
        Shape* buildShape();
        Bunker* bunkerPointer;
        int hits;
        int requiredHits;

    public:
        void update(const float);
        LifePointsBar(int life, Bunker* bunker);
        void decreasePoints();
        bool hasEnded();
};

#endif