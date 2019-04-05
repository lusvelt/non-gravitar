#ifndef _BUNKER_H_
#define _BUNKER_H_

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include "Object.hpp"
#include "Declarations.hpp"
#include "LifePointsBar.hpp"

using namespace sf;
using namespace std;



class Bunker : public Object {
    protected:
        Shape* buildShape();
        LifePointsBar* life;
        float bunkerShootTime;

    public:
        Bunker();
        virtual void shoot();
        virtual void update(const float);
        virtual void onCollisionEnter(Object*);
};

#endif