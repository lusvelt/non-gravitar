#ifndef _PLANET_H_
#define _PLANET_H_

#include "Declarations.hpp"

#include "Object.hpp"
#include "Scene.hpp"

class Planet : public Scene, public Object {
    private:
        float radius;
        vector<Vector2f> points;
        Shape* buildShape(float);

    protected:

    public:
        void onCollisionEnter(Object*);
        Planet(Vector2f);
        float getRadius();
        void update(float);
};

#endif