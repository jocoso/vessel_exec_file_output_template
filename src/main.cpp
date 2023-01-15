// Include list

#include "scene.hpp"
#include "scenes/charsel_scn.hpp"

void on_click(void) {
    std::cout << "Clickily click\n";
}

int main() {
    sf::RenderWindow window(sf::VideoMode(0, 0), "SFML", sf::Style::Fullscreen);
    window.setFramerateLimit(45);

    // Testing Character Selection Scene
    CharacterSelectionScene cs_scn(&window);


    sf::Event event;
    while(window.isOpen()) {

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        cs_scn.draw(window);
    }

    return 0;
}


