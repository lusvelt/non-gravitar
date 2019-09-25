#ifndef _LINE_H_
#define _LINE_H_

#include "Declarations.hpp"

#include "Object.hpp"

class Line : public Object {
    private:
        Shape* buildShape(Vector2f);

    public:
        Line(Vector2f, Vector2f);
        void update(const float);
};

#endif