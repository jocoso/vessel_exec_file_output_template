// Include list
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include <iostream>
#include "scene.hpp"

int main() {
    sf::Vector2f winsize(1000, 800);
    kra::Scene scn("images/map.jpg", winsize);
    sf::RenderWindow window(sf::VideoMode(winsize.x, winsize.y), "SFML");
    window.setFramerateLimit(45);

    sf::Event event;
    while(window.isOpen()) {

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        scn.update(window);
    }

    return 0;
}


