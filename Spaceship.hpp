#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

#include <SFML/Graphics.hpp>
#include "Declarations.hpp"

using namespace sf;

class Spaceship {
    private:
        Vector2f position;
        float rotation;
        Vector2f speed;
        Vector2f acceleration;
        float angularSpeed;
        ConvexShape shape;

        void buildShape();
        void resetAccelerationAndAngularSpeed();
        void accelerateForward();
        void accelerateBackward();
        void rotateLeft();
        void rotateRight();
        void updateTransform();

    public:
        Spaceship();
        ConvexShape getShape();
        void update();
};

#endif