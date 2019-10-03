#ifndef _SCENE_H_
#define _SCENE_H_

#include "Config.hpp"

#include "Object.hpp"
#include "Camera.hpp"

class Camera;
class Object;

class Scene {
    private:
        Camera* camera;
        vector<Object *> objects;

    protected:
        string type;
        Point entryPoint;

    public:
        Scene(Camera*);
        Scene(Camera*, Point);
        Camera* getCamera();
        vector<Object*> *getObjects();
        void addObject(Object*);
        void addObject(Object*, Point);
        bool contains(Object*);
        string getType();
        bool compareType(string);
        const void update();
        Point getEntryPoint();
};

#endif