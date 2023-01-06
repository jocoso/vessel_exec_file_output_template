// Include list
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include <iostream>
#include "scene.hpp"
#include "text.hpp"

int main() {
    sf::Vector2f winsize(1500, 800);
    sf::Vector2f pos(600, 10);
    
    kra::Scene scn("images/char_select_bg.png", winsize);
    kra::Text *txt = new kra::Text("The body rots", pos);
    txt->setFont("Cinzel.ttf");

    scn.addComponent(txt);

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


