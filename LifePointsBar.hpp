#ifndef _LIFEPOINTSBAR_H_
#define _LIFEPOINTSBAR_H_

#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include "Object.hpp"

using namespace sf;
using namespace std;

class LifePointsBar : public Object{
    private:
        Shape* buildShape();
        float length;
        int hit;
        int requiredHit;

    public:
        void update(const float);
        LifePointsBar(int life);
        void decreasePoints();
        bool controlLife();
};

#endif