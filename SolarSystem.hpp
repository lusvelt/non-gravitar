#ifndef _SOLAR_SYSTEM_H_
#define _SOLAR_SYSTEM_H_
#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include <vector>
#include "Planet.hpp"
#include "Camera.hpp"
#include "Object.hpp"
#include "Engine.hpp"
#include "Scene.hpp"

class SolarSystem : public Scene {
    private:
        Shape* buildShape();
        vector<Planet*> vectorPlanets;;

    public:
        SolarSystem();
        virtual void update(const float);
};

#endif