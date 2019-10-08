#ifndef _PLANET_H_
#define _PLANET_H_

#include "../config/Declarations.hpp"

#include "../../engine/Object.hpp"
#include "../../engine/Scene.hpp"
#include "Surface.hpp"

class Planet : public Scene, public Object {
    private:
        float radius;
        vector<Point> points;
        vector<Surface*> surfaces;
        Shape* buildShape();
        void buildSurface();
        void populateSegment(Segment*, int, int);
        int bunkerCount;
        int score;

    protected:

    public:
        void onCollisionEnter(Object*);
        Planet(Point, int);
        float getRadius();
        void update();
        bool hasNoBunkers();
        void bunkerDestroyed();
        int getScore();
};

#endif