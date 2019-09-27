#ifndef _GAME_H_
#define _GAME_H_

#include "Config.hpp"

#include "Scene.hpp"

class Game {
    private:
        int viewWidth;
        int viewHeight;
        string title;
        int framerateLimit;

    protected:
        vector<Scene*> scenes;

    public:
        Game(string, int, int);
        Game(string, int, int, int);
        int getViewWidth();
        int getViewHeight();
        string getTitle();
        int getFramerateLimit();
        int getOutOfBoundsOffsetX();
        int getOutOfBoundsOffsetY();
};

#endif