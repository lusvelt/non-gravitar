#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include "Line.hpp"

class Segment : public Line {
    protected:
        Point p1;
        Point p2;

    public:
        Segment(Point p1, Point p2);
        bool bandContains(Point p);
        Vector getVector();
        float getLength();
        Point getP1();
        Point getP2();
        Point getPM();
};

#endif
