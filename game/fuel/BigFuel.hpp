#include "Fuel.hpp"
#include "../../engine/Object.hpp"
#include "../config/Declarations.hpp"

class BigFuel : public Fuel {
    private:
        Shape* buildShape();
    public:
        BigFuel();
};