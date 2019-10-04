#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

#include "../config/Declarations.hpp"

#include "../../engine/Object.hpp"

class Spaceship : public Object {
    private:
        float shootCd;
        void resetAccelerationAndAngularSpeed();
        void accelerateForward();
        void accelerateBackward();
        void rotateLeft();
        void rotateRight();
        Shape* buildShape();
        void shoot();
        void onBoundHit(Bound);
        bool isOutOfRadius();
        void backToPrevScene();
        int totalFuel;
        

    public:
        Spaceship();
        void update();
        void onCollisionEnter(Object*);
        void getFuel(int);
};

#endif