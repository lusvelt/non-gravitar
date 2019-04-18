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
        string sourceTag;

    public:
        Bullet(Vector2f position, Vector2f speed, string sourceTag);
        void update(const float deltaTime);
        void onCollisionEnter(Object*);
        string getSourceTag();
        bool compareSourceTag(string tag);
        
};

#endif