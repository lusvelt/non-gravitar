#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <SFML/System.hpp>

using namespace sf;
using namespace std;

class Camera {
  private:
    Vector2f position;
    const void (*updateFunction)(Camera*, const float);

  public:
    Camera(const void (*updateFunction)(Camera*, const float));
    void setPosition(Vector2f position);
    void update(const float deltaTime);
};

#endif