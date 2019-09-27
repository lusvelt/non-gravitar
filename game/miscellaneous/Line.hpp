#ifndef _LINE_H_
#define _LINE_H_

#include "../config/Declarations.hpp"

#include "../../engine/Object.hpp"

class Line : public Object {
    private:
        Vector2f coordinates;
        Shape* buildShape();

    public:
        Line(Vector2f, Vector2f);
        void update();
};

#endif