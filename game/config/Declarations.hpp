#ifndef _DECLARATIONS_H_
#define _DECLARATIONS_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Non-Gravitar"
#define FUEL_START_VALUE 10000
#define LIVES_START_VALUE 5
#define ACCELERATION_MODULE 200.f
#define ANGULAR_SPEED_MODULE 120.f
#define BULLET_BASE_SPEED 1000.f
#define SPACESHIP_SHOOT_COOLDOWN 0.33f
#define MIN_PLANETS 2
#define MAX_PLANETS 2
#define BUNKER_WIDTH 400
#define BUNKER_HEIGHT 550.f
#define N_BLOCKS 9
#define N_COLUMNS 3
#define MARGIN 30
#define STANDARD_BUNKER_ANGLE 45.f
#define PLANET_LINE_THICKNESS 3.f
#define PLANET_SCALE 100
#define PIXELS_PER_POINT 200
#define PLANET_POINT_RANGE_SCALE_X 0.8f
#define PLANET_POINT_RANGE_SCALE_Y 1.2f
#define SPACESHIP_DISTANCE_FROM_FLOOR 200.f
#define BULLET_DISTANCE_RADIUS 10.f
#define PLANET_ATMOSPHERE_HEIGHT 1000
#define PLANET_RANGE_RADIUS 3500
#define PLANET_MIN_RADIUS 500
#define FRAMERATE_LIMIT 60
#define BULLET_COLLISION_RADIUS 10
#define SPACESHIP_SCALE 1.f

using namespace sf;
using namespace std;

#endif