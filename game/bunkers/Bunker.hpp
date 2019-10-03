#ifndef _BUNKER_H_
#define _BUNKER_H_

#include "../config/Declarations.hpp"
#include "../../engine/geometry/Segment.hpp"

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
        virtual Point shootPoint() = 0;
        float bulletSpeed;
        int bunkerPoints;

    public:
        Bunker(Shape* shape, int lifePoints, float maxRay, float angularFactor, float bunkerCoolDown);
        void shoot();
        void update();
        void onCollisionEnter(Object*);
        virtual void studyFireAngle();
        Point getLPBCoordinates();
        void setPosition(Segment*);
};


#endif