#ifndef _FIXED_CAMERA_H_
#define _FIXED_CAMERA_H_

#include "../config/Declarations.hpp"

#include "../../engine/Camera.hpp"

class FixedCamera : public Camera {
    public:
        void update();
};

#endif