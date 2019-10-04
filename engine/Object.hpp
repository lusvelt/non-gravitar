#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Config.hpp"

#include "Bound.hpp"
#include "Scene.hpp"

class Scene;

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
        vector<Object*> children;
        bool visible;
        Scene* currentScene;
        String type;

    public:
        Object(Point position, float rotation);
        Object(Shape* shape, Point position, float rotation);
        Object(Shape* shape);
        Object(Object*);
        virtual ~Object();
        Point getPosition();
        void setRotation(float);
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
        vector<Object*> getChildren();
        void addChild(Object*);
        void hide();
        void show();
        bool isVisible();
        Scene* getCurrentScene();
        void setCurrentScene(Scene*);
        void moveOf(Vector);
        bool instanceOf(String);
        
};

#endif