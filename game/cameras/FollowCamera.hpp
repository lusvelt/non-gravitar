#ifndef _FOLLOW_CAMERA_H_
#define _FOLLOW_CAMERA_H_

#include "../config/Declarations.hpp"

#include "../../engine/Camera.hpp"

class FollowCamera : public Camera {
    public:
        void update();
};

#endif