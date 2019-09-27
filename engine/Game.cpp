#include "Game.hpp"

#include "Engine.hpp"

Game::Game(string title, int width, int height) {
    this->title = title;
    this->viewWidth = width;
    this->viewHeight = height;
    this->framerateLimit = DEFAULT_FRAMERATE;
}

Game::Game(string title, int width, int height, int framerateLimit) {
    this->title = title;
    this->viewWidth = width;
    this->viewHeight = height;
    this->framerateLimit = framerateLimit;
}

int Game::getViewWidth() {
    return viewWidth;
}

int Game::getViewHeight() {
    return viewHeight;
}

string Game::getTitle() {
    return title;
}

int Game::getFramerateLimit() {
    return framerateLimit;
}

int Game::getOutOfBoundsOffsetX() {
    return viewWidth / 2;
}

int Game::getOutOfBoundsOffsetY() {
    return viewHeight / 2;
}