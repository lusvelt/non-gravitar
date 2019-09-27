#ifndef _SCENE_H_
#define _SCENE_H_

#include "Config.hpp"

#include "Object.hpp"
#include "Camera.hpp"

class Camera;

class Scene {
    private:
        Camera* camera;
        vector<Object *> objects;

    protected:
        string type;
        Vector2f entryPoint;

    public:
        Scene(Camera*);
        Scene(Camera*, Vector2f);
        Camera* getCamera();
        vector<Object*> *getObjects();
        void addObject(Object*);
        void addObject(Object*, Vector2f);
        bool contains(Object*);
        string getType();
        bool compareType(string);
        const void update();
        Vector2f getEntryPoint();
};

#endif