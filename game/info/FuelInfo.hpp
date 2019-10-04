#ifndef _FUEL_INFO_H_
#define _FUEL_INFO_H_

#include "../../engine/Info.hpp"

class FuelInfo : public Info {
    private:
        Shape* buildShape();
    
    public:
        FuelInfo();
        void update();
};

#endif