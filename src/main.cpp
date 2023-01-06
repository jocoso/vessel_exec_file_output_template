// Include list

#include "utils.hpp"
#include "scene.hpp"
#include "text.hpp"

int main() {

    sf::Vector2f winsize(1500, 800);  // Screen size
    
    // Creating an scene
    // A scene is a self contained entity that display the components
    //   the user gives it.
    kra::Scene scn("images/char_select_bg.png", winsize);

    // Creating mandatory edgy text
    kra::Text *txt = new kra::Text("The body is a vessel", 500.f, 10.f);
    kra::Text *txt2 = new kra::Text("Pick yours", 600.f, 50.f);

    // Changing to mandatory vampire the masquerade edgy font
    sf::Font cinzel = utils::loadFont("Cinzel.ttf");
    txt->setFont(cinzel);
    txt2->setFont(cinzel);

    // Greyish red
    txt->setFillColor(sf::Color(150, 100, 100));
    txt2->setFillColor(sf::Color(150, 100, 100));

    // Adding component to scene will make sure to render it
    scn.addComponent(txt);
    scn.addComponent(txt2);

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


