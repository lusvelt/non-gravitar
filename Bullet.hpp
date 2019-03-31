#ifndef _BULLET_H_
#define _BULLET_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include "Object.hpp"

using namespace sf;

class Bullet : public Object {
    private:
        Shape* buildShape();


    public:
        Bullet(Vector2f position, Vector2f speed);
        void update(const float deltaTime);
        void onCollisionEnter(Object*);
};

#endif