#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include "Object.hpp"

using namespace sf;

class Spaceship : public Object {
    private:
        void resetAccelerationAndAngularSpeed();
        void accelerateForward();
        void accelerateBackward();
        void rotateLeft();
        void rotateRight();
        void updateTransform(const float deltaTime);
        static ConvexShape* buildShape();

    public:
        Spaceship();
        void update(const float deltaTime);
};

#endif