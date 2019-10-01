#include "../config/Declarations.hpp"
#include "../../engine/Object.hpp"

class TractorBeam : public Object {
    private:
    Shape* buildShape();

    public:
    TractorBeam();
    void update();
};

