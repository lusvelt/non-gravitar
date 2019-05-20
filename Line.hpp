#ifndef _LINE_H_
#define _LINE_H_
#include <SFML/Graphics.hpp>
#include "Declarations.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "Object.hpp"

using namespace sf;

class Line : public Object {
    private:
        Shape* buildShape(Vector2f);

    public:
        Line(Vector2f, Vector2f);
        void update(const float);
};

#endif