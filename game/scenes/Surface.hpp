#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "../config/Declarations.hpp"

#include "../../engine/Object.hpp"
#include "../../engine/geometry/Segment.hpp"

class Surface : public Object {
    private:
        Segment* segment;
        Shape* buildShape();

    public:
        Surface(Point, Point);
        void update();
        bool collidesWith(Object*);
        Segment* getSegment();
};

#endif