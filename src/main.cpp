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
    sf::Image bg;
    if(!bg.loadFromFile("images/map.jpg")) {
        std::cout << "Cannot load Image" << "\n";
        return -1;
    }

    kra::Scene scn(bg);
    sf::RenderWindow window(sf::VideoMode(scn.getSize().x, scn.getSize().y), "SFML");

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            window.clear();
            scn.play(window);
            window.display();
            
        }
    }

    return 0;
}


