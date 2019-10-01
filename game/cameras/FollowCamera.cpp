#include "FollowCamera.hpp"

#include "../../engine/Engine.hpp"

void FollowCamera::update() {
    Point spaceshipPosition = Engine::getObjectByTag("Spaceship")->getPosition();
    this->setPosition(Point(spaceshipPosition.x - WINDOW_WIDTH / 2, spaceshipPosition.y - WINDOW_HEIGHT / 2));
}