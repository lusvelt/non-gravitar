#ifndef _BUNKER_H
#define _BUNKER_H

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include "Object.hpp"
#include "Declarations.hpp"
#include "LifePointsBar.hpp"

using namespace sf;
using namespace std;


class Bunker : public Object {
    protected:
        virtual Shape* buildShape() = 0;
        LifePointsBar* life;
        float bunkerShootTime;
        float fireAngle;
        float maxRay;
        float angularFactor;
        float bunkerCoolDown;
    public:
        Bunker(Shape* shape, int lifePoints, float maxRay, float angularFactor, float bunkerCoolDown);
        void shoot();
        void update(const float);
        void onCollisionEnter(Object*);
        virtual void studyFireAngle() = 0;
};


#endif