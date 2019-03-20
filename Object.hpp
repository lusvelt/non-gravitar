#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Object {
    protected:
        Vector2f position;
        Vector2f speed;
        Vector2f acceleration;
        float rotation;
        float angularSpeed;
        Shape* shape;

    public:
        Object(Shape* shape, Vector2f position, float rotation);
        Vector2f getPosition();
        virtual Shape* getShape();
        virtual void update(const float deltaTime);

};

#endif