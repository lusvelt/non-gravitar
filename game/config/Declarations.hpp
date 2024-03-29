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
#define ACCELERATION_MODULE 200.f
#define ANGULAR_SPEED_MODULE 250.f
#define BULLET_BASE_SPEED 1000.f
#define SPACESHIP_SHOOT_COOLDOWN 0.33f
#define MIN_PLANETS 2
#define MAX_PLANETS 2
#define BUNKER_WIDTH 400
#define BUNKER_HEIGHT 550.f
#define N_BLOCKS 9
#define N_COLUMNS 3
#define N_ROWS 3
#define MARGIN 50
#define STANDARD_BUNKER_ANGLE 45.f
#define PLANET_LINE_THICKNESS 3.f
#define PLANET_SCALE 100
#define PIXELS_PER_POINT 200
#define PLANET_POINT_RANGE_SCALE_X 0.8f
#define PLANET_POINT_RANGE_SCALE_Y 1.2f
#define SPACESHIP_DISTANCE_FROM_FLOOR 200.f
#define BULLET_DISTANCE_RADIUS 10.f
#define PLANET_ATMOSPHERE_HEIGHT 700
#define PLANET_MAX_RADIUS 4000
#define PLANET_MIN_RADIUS 1500
#define FRAMERATE_LIMIT 60
#define BULLET_COLLISION_RADIUS 10
#define SPACESHIP_SCALE 1.f
#define SMALL_FUEL_LIKELYHOOD 10
#define BIG_FUEL_LIKELYHOOD 5
#define BUNKER_LIKELYHOOD 30
#define SPACESHIP_COLLISION_RADIUS 10
#define MAX_FUEL 5000
#define FUEL_SCALE_COEFFICIENT 150
#define STARTING_LIVES 5
#define BUNKER_BULLET_SPEED 500.f
#define RANGE_NO_BUNKERS 300.f

using namespace sf;
using namespace std;

#endif