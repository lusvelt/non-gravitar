#ifndef _LINE_H_
#define _LINE_H_

#include "../Config.hpp"

class Line {
    protected:
        float m;
        float q;
    
    public:
        Line(float m, float q);
        Line(Point p1, Point p2);
        float getDistance(Point);
        Line* getPerpendicularThroughPoint(Point p);
        float evaluateY(float x);
        
};

#endif