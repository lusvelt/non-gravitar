#ifndef _SPACESHIP_BULLET_H_
#define _SPACESHIP_BULLET_H_

#include "../config/Declarations.hpp"

#include "Bullet.hpp"

class SpaceshipBullet : public Bullet {
    private:
        Shape *buildShape();

    public:
        SpaceshipBullet(Point position, Point speed);
        void onCollisionEnter(Object*);
};

#endif