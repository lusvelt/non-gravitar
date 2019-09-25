#ifndef _THREE_DIRECTION_BUNKER_H
#define _THREE_DIRECTION_BUNKER_H

#include "Declarations.hpp"

#include "Bunker.hpp"

class ThreeDirectionBunker : public Bunker {
    private:
        Shape* buildShape();

    public:
        ThreeDirectionBunker();
        float shootPoint();
        void studyFireAngle();
};


#endif