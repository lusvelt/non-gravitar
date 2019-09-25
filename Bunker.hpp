#ifndef _BUNKER_H
#define _BUNKER_H

#include "Declarations.hpp"

#include "LifePointsBar.hpp"

class Bunker : public Object {
    protected:
        virtual Shape* buildShape() = 0;
        LifePointsBar* life;
        float bunkerShootTime;
        float fireAngle;
        float maxRay;
        float angularFactor;
        float bunkerCoolDown;
        virtual float shootPoint() = 0;
        float bulletSpeed;

    public:
        Bunker(Shape* shape, int lifePoints, float maxRay, float angularFactor, float bunkerCoolDown);
        void shoot();
        void update(const float);
        void onCollisionEnter(Object*);
        virtual void studyFireAngle();
        float getBaseLength();
        Vector2f getLPBCoordinates();
};


#endif