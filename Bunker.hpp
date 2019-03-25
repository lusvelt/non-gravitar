#ifndef _BUNKER_H_
#define _BUNKER_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.hpp"
#include "Object.hpp"
#include "Declarations.hpp"

using namespace sf;
using namespace std;



class Bunker : public Object {
    protected:
        static Shape* buildShape();
        int lifePoints;
    public:
        Bunker();
        // virtual vector<Bullet*> shoot();
        virtual void update(const float);
};

#endif