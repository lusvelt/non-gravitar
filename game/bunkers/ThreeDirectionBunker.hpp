#ifndef _THREE_DIRECTION_BUNKER_H_
#define _THREE_DIRECTION_BUNKER_H_

#include "../config/Declarations.hpp"

#include "Bunker.hpp"

class ThreeDirectionBunker : public Bunker {
    private:
        Shape* buildShape();

    public:
        ThreeDirectionBunker();
        Point shootPoint();
        void studyFireAngle();
};


#endif