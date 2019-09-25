#ifndef _BULLET_H_
#define _BULLET_H_

#include "Declarations.hpp"

#include "Object.hpp"

class Bullet : public Object {
    private:
        Shape* buildShape();
        string sourceTag;

    protected:

    public:
        Bullet(Vector2f position, Vector2f speed, string sourceTag);
        void update(const float deltaTime);
        void onCollisionEnter(Object*);
        string getSourceTag();
        bool compareSourceTag(string tag);
        
};

#endif