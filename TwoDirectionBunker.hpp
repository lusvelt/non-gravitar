#ifndef _TWO_DIRECTION_BUNKER_H
#define _TWO_DIRECTION_BUNKER_H

#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"

class TwoDirectionBunker : public Bunker{
    private:
        Shape* buildShape();

    public:
        TwoDirectionBunker();
        float shootPoint();
        void studyFireAngle();
};


#endif