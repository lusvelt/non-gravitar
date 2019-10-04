#ifndef _MOVING_LIGHT_H_
#define _MOVING_LIGHT_H_

#include "../config/Declarations.hpp"

#include "../../engine/Object.hpp"

class MovingLight : public Object {
    private:
        Shape* buildShape();
    public:
        MovingLight();
        void update();
};

#endif