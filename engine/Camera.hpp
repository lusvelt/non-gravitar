#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Config.hpp"

#include "Object.hpp"

class Camera {
  private:
    Vector2f position;

  public:
    Camera();
    Vector2f getPosition();
    void setPosition(Vector2f position);
    virtual void update() = 0;
};

#endif