#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <SFML/System.hpp>
#include <vector>
#include "Object.hpp"

using namespace sf;
using namespace std;

class Camera {
  private:
    Vector2f position;
    const void (*updateFunction)(Camera*, const float, vector<Object*>*);

  public:
    Camera(const void (*updateFunction)(Camera*, const float, vector<Object*>*));
    Vector2f getPosition();
    void setPosition(Vector2f position);
    void update(const float deltaTime);
};

#endif