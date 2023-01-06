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

    kra::Scene scn("images/map.jpg");
    sf::RenderWindow window(sf::VideoMode(scn.getSize().x, scn.getSize().y), "SFML");


    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            window.clear();
            scn.update(window);
            window.display();
            
        }
    }

    return 0;
}


