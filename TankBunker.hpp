#ifndef _TANK_BUNKER_H
#define _TANK_BUNKER_H

#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"

class TankBunker : public Bunker{
    private:
        Shape* buildShape();
    public:
        TankBunker();
        float shootPoint();
        void studyFireAngle();
};


#endif