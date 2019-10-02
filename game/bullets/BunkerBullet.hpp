#ifndef _BUNKER_BULLET_H_
#define _BUNKER_BULLET_H_

#include "../config/Declarations.hpp"

#include "Bullet.hpp"

class BunkerBullet : public Bullet {
    private:
        Shape *buildShape();

    public:
        BunkerBullet(Point position, Vector speed);
        void onCollisionEnter(Object *);
};

#endif