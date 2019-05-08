#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Declarations.hpp"

using namespace sf;
using namespace std;

class Object {
    protected:
        Vector2f position;
        Vector2f speed;
        Vector2f acceleration;
        float rotation;
        float angularSpeed;
        string tag;
        Shape* shape;
        virtual Shape* buildShape() = 0;
        Object* prevPointer;

    public:
        Object(Shape* shape, Vector2f position, float rotation);
        Object(Object*);
        virtual ~Object();
        Vector2f getPosition();
        string getTag();
        bool compareTag(string);
        Shape* getShape();
        float getRotation();
        Object* getPrevPointer();
        virtual void updateTransform(const float);
        virtual void onCollisionEnter(Object*);
        virtual void onBoundHit(Bound);
        virtual void update(const float deltaTime) = 0;
        bool isAClone();
};

#endif