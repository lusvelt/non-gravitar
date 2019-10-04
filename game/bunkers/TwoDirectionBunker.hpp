#ifndef _TWO_DIRECTION_BUNKER_H_
#define _TWO_DIRECTION_BUNKER_H_

#include "../config/Declarations.hpp"

#include "Bunker.hpp"

class TwoDirectionBunker : public Bunker {
    private:
        Shape* buildShape();

    public:
        TwoDirectionBunker();
        void studyFireAngle();
};


#endif