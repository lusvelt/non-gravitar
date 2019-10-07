#ifndef _FUEL_BAR_H_
#define _FUEL_BAR_H_

#include "../config/Declarations.hpp"
#include "../../engine/Object.hpp"

class FuelBar : public Object {
    private:
        Shape* buildShape();

    public:
        FuelBar();
};

#endif