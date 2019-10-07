#ifndef _SOLAR_SYSTEM_H_
#define _SOLAR_SYSTEM_H_

#include "../config/Declarations.hpp"

#include "../../engine/Scene.hpp"
#include "Planet.hpp"

class Scene;

class SolarSystem : public Scene {
    private:
        vector<Planet*> planets;
        void addPlanet(Planet*);
        int planetCount;
    public:
        SolarSystem();
        const void generatePlanets();
        virtual void update();
        void onLoad();
};

#endif