#ifndef _SOLAR_SYSTEM_H_
#define _SOLAR_SYSTEM_H_

#include "Declarations.hpp"

#include "Scene.hpp"
#include "Planet.hpp"

class Scene;

class SolarSystem : public Scene {
    private:
        vector<Planet*> planets;
    public:
        SolarSystem();
        const void generatePlanets();
        virtual void update(const float);
};

#endif