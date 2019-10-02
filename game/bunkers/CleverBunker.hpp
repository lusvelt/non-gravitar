#ifndef _CLEVER_BUNKER_H_
#define _CLEVER_BUNKER_H_

#include "../config/Declarations.hpp"

#include "Bunker.hpp"

class CleverBunker : public Bunker {
    private:
        Shape* buildShape();
    public:
        CleverBunker();
        void studyFireAngle();
        Point shootPoint();
        void shoot();
};


#endif