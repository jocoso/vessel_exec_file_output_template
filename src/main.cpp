// Include list
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "scenes.h"
#include "vessel_factory.h"

int main() {
    // All components wil be created in the VesselFactory
    VesselFactory *_factory = VesselFactory::GetInstance();
    Scene *scn = _factory->new_scene(
                                        "Scene 0",   // Name
                                        500.0,       // Width
                                        700.0,       // Height
                                        100,         // Red
                                        100,         // Green
                                        100          // Blue
                                    );

    sf::RenderWindow window(sf::VideoMode(500, 700), "trial 1");

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(*scn);
        window.display();
    }

    free(scn);
    free(_factory);
    return 0;
}


