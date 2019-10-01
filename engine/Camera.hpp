#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Config.hpp"

#include "Object.hpp"

class Camera {
  private:
    Point position;

  public:
    Camera();
    Point getPosition();
    void setPosition(Point position);
    virtual void update() = 0;
};

#endif