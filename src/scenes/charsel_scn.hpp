#ifndef CHARSEL_SCN_HPP
#define CHARSEL_SCN_HPP

#include "../scene.hpp"


class CharacterSelectionScene : public kra::Scene {
public:
    CharacterSelectionScene(sf::RenderWindow *_window) : 
        kra::Scene("images/char_select_bg.png", _window) {}
    
    void init(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    
};


#endif // SCENE_0_HPP