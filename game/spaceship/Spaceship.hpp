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
        int lifes;
        

    public:
        Spaceship();
        void update();
        void onCollisionEnter(Object*);
<<<<<<< HEAD
        void addFuel(int);
        int getLife();
=======
        void getFuel(int);
        int getLife();
        int getScore(int);
        int scores;
>>>>>>> 1f196095beb8198f2bf91bfc7cc4bc8bfa09a343
};

#endif