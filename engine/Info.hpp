#ifndef _INFO_H_
#define _INFO_H_

#include "Config.hpp"

#include "Object.hpp"

class Info {
    protected:
        string type;
        Object* object;
        Text* text;
    
    public:
        Info(Object*, Point);
        Info(Text*, Point);
        string getType();
        Object* getObject();
        Text* getText();
        virtual void update();
};

#endif