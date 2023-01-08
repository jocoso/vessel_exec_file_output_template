#ifndef CHARSEL_SCN_HPP
#define CHARSEL_SCN_HPP

#include "../scene.hpp"
#include "../button.hpp"


class CharacterSelectionScene : public kra::Scene {
public:
    CharacterSelectionScene(sf::RenderWindow *_window) : 
        kra::Scene("images/char_select_bg.png", _window) {
            
            // Keeping it neat
            sf::Vector2f winsize(_window->getSize().x, _window->getSize().y);

            kra::Button *card0 = new kra::Button(
                "images/card0.png", 
                sf::Vector2f(400, 820),
                sf::Vector2f(50, (winsize.y/2)-410)
            );

            auto on_click = []() {
                std::cout << "clickily click\n";
            }

            card0->onClick(on_click);

            addComponent(card0); // The class will automatically free the memory
    }

    
protected:
    virtual void update(sf::RenderWindow &window) override;
    
};


#endif // SCENE_0_HPP