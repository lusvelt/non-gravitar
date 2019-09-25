#ifndef _TWO_DIRECTION_BUNKER_H
#define _TWO_DIRECTION_BUNKER_H

#include "Declarations.hpp"

#include "Bunker.hpp"

class TwoDirectionBunker : public Bunker {
    private:
        Shape* buildShape();

    public:
        TwoDirectionBunker();
        float shootPoint();
        void studyFireAngle();
};


#endif