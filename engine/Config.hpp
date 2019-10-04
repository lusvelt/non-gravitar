#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using namespace sf;

#define DEFAULT_FRAMERATE 60
#define OUT_OF_BOUNDS_OFFSET_X 400
#define OUT_OF_BOUNDS_OFFSET_Y 300
#define SGN(X) ((X) > 0 ? 1 : (((X) < 0) ? -1 : 0))

typedef Vector2f Point;
typedef Vector2f Vector;