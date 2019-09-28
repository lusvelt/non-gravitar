#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Config.hpp"

#include "Bound.hpp"

class Object {

    protected:
        Vector2f position;
        Vector2f speed;
        Vector2f acceleration;
        float rotation;
        float angularSpeed;
        string tag;
        Shape* shape;
        Object* prevPointer;
        bool deleteIfOutOfBounds;

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
        virtual Shape* buildShape() = 0;
        virtual void updateTransform();
        virtual void onCollisionEnter(Object*);
        virtual void onBoundHit(Bound);
        virtual void update();
        virtual bool collidesWith(Object*);
        bool isAClone();
        void setPosition(Vector2f position);
        void setSpeed(Vector2f speed);
        bool isOutOfBounds();
        bool shouldBeDeletedIfOutOfBounds();
        
};

#endif