#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>

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

    public:
        Object(Shape* shape, Vector2f position, float rotation);
        virtual ~Object();
        Vector2f getPosition();
        string getTag();
        bool compareTag(string);
        Shape* getShape();
        float getRotation();
        virtual void updateTransform(const float);
        virtual void onCollisionEnter(Object*);
        virtual void update(const float deltaTime) = 0;

};

#endif