#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Config.hpp"

#include "Bound.hpp"

class Object {

    protected:
        Point position;
        Point speed;
        Point acceleration;
        float rotation;
        float angularSpeed;
        string tag;
        Shape* shape;
        Object* prevPointer;
        bool deleteIfOutOfBounds;

    public:
        Object(Point position, float rotation);
        Object(Shape* shape, Point position, float rotation);
        Object(Object*);
        virtual ~Object();
        Point getPosition();
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
        void setPosition(Point position);
        void setSpeed(Point speed);
        bool isOutOfBounds();
        bool shouldBeDeletedIfOutOfBounds();
        
};

#endif