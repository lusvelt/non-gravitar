#ifndef _FUEL_H_
#define _FUEL_H_
#include "../../engine/Object.hpp"
#include "../config/Declarations.hpp"
#include "../../engine/geometry/Segment.hpp"

class Fuel: public Object{
    protected:
        int fuelAmount;

    public:
         void update();
         Fuel(Shape* shape);
         void setPosition(Segment*);
         int getFuelAmount();
};

#endif