#ifndef _CLEVER_BUNKER_H
#define _CLEVER_BUNKER_H

#include "Declarations.hpp"

#include "Bunker.hpp"

class CleverBunker : public Bunker {
    private:
        Shape* buildShape();
    public:
        CleverBunker();
        void studyFireAngle();
        float shootPoint();
        void shoot();
};


#endif