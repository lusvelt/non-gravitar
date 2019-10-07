#ifndef _LIVES_H_
#define _LIVES_H_
#include "../../engine/Info.hpp"
#include "../spaceship/Spaceship.hpp"



class Lives: public Info{
    private:

    public:
    Lives(float);
    void update();

};

#endif