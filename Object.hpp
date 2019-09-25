#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Declarations.hpp"

class Object {

    private:

    protected:
        Vector2f position;
        Vector2f speed;
        Vector2f acceleration;
        float rotation;
        float angularSpeed;
        string tag;
        Shape* shape;
        Object* prevPointer;

    public:
        Object(Vector2f position, float rotation);
        Object(Shape* shape, Vector2f position, float rotation);
        Object(Object*);
        virtual ~Object();
        Vector2f getPosition();
        float getPolarRadius();
        string getTag();
        bool compareTag(string);
        Shape* getShape();
        float getRotation();
        Object* getPrevPointer();
        virtual void updateTransform(const float);
        virtual void onCollisionEnter(Object*);
        virtual void onBoundHit(Bound);
        virtual void update(const float deltaTime);
        bool isAClone();
        void setPosition(Vector2f position);
        void setSpeed(Vector2f speed);
};

#endif