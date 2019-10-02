#include "Fuel.hpp"
#include "../../engine/Object.hpp"
#include "../config/Declarations.hpp"

class SmallFuel : public Fuel {
    private:
        Shape* buildShape();
    public:
        SmallFuel();
};