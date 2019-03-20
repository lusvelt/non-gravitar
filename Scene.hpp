#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>
#include "Camera.hpp"
#include "Scene.hpp"
#include "Object.hpp"

using namespace std;
using namespace sf;

class Camera;

class Scene {
    private:

    public:
        Camera* camera;
        vector<Object*> objects;
        Scene(const void (*cameraFunction)(Camera*, const float));
        virtual void update(const float deltaTime);
};

#endif