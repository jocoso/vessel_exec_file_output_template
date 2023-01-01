// Include list
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "scenes.h"
#include "button.h"
#include "vessel_factory.h"

int main() {
    float width = 500.f;
    float height = 700.f;

    sf::Vector2f v1(20, 30);
    sf::Vector2f v2(20, 30);

    sf::Font font;
    if(!font.loadFromFile("arial.ttf")) {

    }

    gui::Button b(0, v1, v2, "hello", font);

    // All components wil be created in the VesselFactory
    VesselFactory *_factory = VesselFactory::GetInstance();
    Scene *scn = _factory->new_scene(
                                        "Scene 0",   // Name
                                        width,       // Width
                                        height,      // Height
                                        100,         // Red
                                        100,         // Green
                                        100          // Blue
                                    );

    sf::RenderWindow window(sf::VideoMode(width, height), "trial 1");

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


