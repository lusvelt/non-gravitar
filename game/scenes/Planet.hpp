#ifndef _PLANET_H_
#define _PLANET_H_

#include "../config/Declarations.hpp"

#include "../../engine/Object.hpp"
#include "../../engine/Scene.hpp"

class Planet : public Scene, public Object {
    private:
        float radius;
        vector<Vector2f> points;
        Shape* buildShape();

    protected:

    public:
        void onCollisionEnter(Object*);
        Planet(Vector2f);
        float getRadius();
        void update();
};

#endif