#ifndef _PLANET_H_
#define _PLANET_H_
#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Scene.hpp"
#include "Declarations.hpp"
#include "Line.hpp"
#include <cmath>

class Planet : public Scene, public Object {
    private:
        float radius;
        vector<Vector2f> points;
        Shape* buildShape(float);
    public:
        void onCollisionEnter(Object*);
        Planet(Vector2f);
        float getRadius();
        void update(float);
};

#endif