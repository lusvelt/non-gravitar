#ifndef _SOLAR_SYSTEM_H_
#define _SOLAR_SYSTEM_H_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Declarations.hpp"
#include <vector>
#include "Planet.hpp"
#include "Camera.hpp"
#include "Object.hpp"
#include "Engine.hpp"
#include "Scene.hpp"

class SolarSystem : public Scene {
    private:
        vector<Planet*> planets;
    public:
        SolarSystem();
        const void generatePlanets(int,int);
        virtual void update(const float);
};

#endif