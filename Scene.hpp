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
        Camera* camera;
        vector<Object*> objects;

    public:
        Scene(const void (*cameraFunction)(Camera*, const float, vector<Object*>*));
        Camera* getCamera();
        vector<Object*> *getObjects();
        void addObject(Object*);
        void update(const float deltaTime);
};

#endif