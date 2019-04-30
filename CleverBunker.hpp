#ifndef _CLEVER_BUNKER_H
#define _CLEVER_BUNKER_H

#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "Bullet.hpp"
#include "Declarations.hpp"
#include "Bunker.hpp"
#include "Object.hpp"
#include "LifePointsBar.hpp"
#include "Spaceship.hpp"

class CleverBunker : public Bunker{
    private:
        Shape* buildShape();
    public:
        CleverBunker();
        void studyFireAngle();
        void shoot();
};


#endif