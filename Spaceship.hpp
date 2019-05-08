#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include "Object.hpp"

using namespace sf;

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

    public:
        Spaceship();
        void update(const float deltaTime);
};

#endif