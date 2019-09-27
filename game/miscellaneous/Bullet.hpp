#ifndef _BULLET_H_
#define _BULLET_H_

#include "../config/Declarations.hpp"

#include "../../engine/Object.hpp"

class Bullet : public Object {
    private:
        Shape* buildShape();
        string sourceTag;

    protected:

    public:
        Bullet(Vector2f position, Vector2f speed, string sourceTag);
        void update();
        void onCollisionEnter(Object*);
        bool compareSourceTag(string tag);
        
};

#endif