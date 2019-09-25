#ifndef _SCENE_H_
#define _SCENE_H_

#include "Declarations.hpp"

#include "Object.hpp"
#include "Camera.hpp"

class Camera;

class Scene {
    private:
        Camera* camera;
        vector<Object *> objects;

    protected:
        string type;

    public:
        Scene(const void (*cameraFunction)(Camera*, const float, vector<Object*>*));
        Camera* getCamera();
        vector<Object*> *getObjects();
        void addObject(Object*);
        void addObject(Object*, Vector2f);
        bool contains(Object*);
        string getType();
        bool compareType(string);
        const void update(const float deltaTime);
};

#endif