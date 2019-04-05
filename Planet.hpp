#ifndef _PLANET_H_
#define _PLANET_H_
#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Scene.hpp"

class Planet : public Scene, public Object {
    private:
        Shape* buildShape();
    public:
        Planet(Vector2f);
        void update(const float);
};

#endif