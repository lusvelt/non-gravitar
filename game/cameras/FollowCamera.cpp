#include "FollowCamera.hpp"

#include "../../engine/Engine.hpp"

void FollowCamera::update() {
    Vector2f spaceshipPosition = Engine::getObjectByTag("Spaceship")->getPosition();
    this->setPosition(Vector2f(spaceshipPosition.x - WINDOW_WIDTH / 2, spaceshipPosition.y - WINDOW_HEIGHT / 2));
}