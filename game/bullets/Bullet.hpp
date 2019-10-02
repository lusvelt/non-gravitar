#ifndef _BULLET_H_
#define _BULLET_H_

#include "../config/Declarations.hpp"

#include "../../engine/Object.hpp"

class Bullet : public Object {
    public:
        Bullet(Shape*, Point position, Vector speed);
        void update();
        void onBoundHit(Bound);
        bool collidesWith(Object*);
        
};

#endif