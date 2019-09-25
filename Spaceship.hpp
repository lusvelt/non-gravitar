#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

#include "Declarations.hpp"

#include "Object.hpp"

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

    public:
        Spaceship();
        void update(const float deltaTime);
};

#endif