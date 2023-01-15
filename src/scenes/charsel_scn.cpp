#include "charsel_scn.hpp"

CharacterSelectionScene::CharacterSelectionScene(sf::RenderWindow *_window) : 
        kra::Scene("images/char_select_bg.png", _window) {
    displayTopMenu();

}

void CharacterSelectionScene::update(sf::RenderWindow &window, sf::Event &event) {
    
}

void CharacterSelectionScene::createText(sf::Vector2f winsize) {
    
}

void CharacterSelectionScene::displayTopMenu() {
    TopMenu *menu = new TopMenu(window, sf::Vector2f(0, 0));
    addComponent(menu);
}