#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Declarations.hpp"
#include "GameController.hpp"

using namespace std;
using namespace sf;
using namespace sf::Style;

int main() {
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    GameController game(window);

    while (window.isOpen()) {
        // Event loop
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Game flow
        game.run();
    }

    return 0;
}