#ifndef _THREE_DIRECTION_BUNKER_H
#define _THREE_DIRECTION_BUNKER_H

#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"

class ThreeDirectionBunker : public Bunker{
    private:
        Shape* buildShape();

    public:
        ThreeDirectionBunker();
        float shootPoint();
        void studyFireAngle();
};


#endif