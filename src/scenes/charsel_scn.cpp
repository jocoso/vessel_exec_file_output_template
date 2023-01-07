#include "charsel_scn.hpp"

void CharacterSelectionScene::init(sf::RenderWindow &window) {
    // Keeping it neat
    sf::Vector2f winsize(window.getSize().x, window.getSize().y);

    kra::Button *card0 = new kra::Button(
        "images/card0.png", 
        sf::Vector2f(400, 820),
        sf::Vector2f(50, (winsize.y/2)-410)
    );

    addComponent(card0); // The class will automatically free the memory
}

void CharacterSelectionScene::update(sf::RenderWindow &window) {}