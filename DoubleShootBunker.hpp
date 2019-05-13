#ifndef _DOUBLE_SHOOT_BUNKER_H
#define _DOUBLE_SHOOT_BUNKER_H

#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"

class DoubleShootBunker : public Bunker{
    private:
        Shape* buildShape();
        int direction;
        float absFireAngle;
        int shot;

    public:
        DoubleShootBunker();
        float shootPoint();
        void studyFireAngle();
};


#endif