#ifndef CHARSEL_SCN_HPP
#define CHARSEL_SCN_HPP

#include "../scene.hpp"
#include "../button.hpp"
#include "../text.hpp"
#include "../input_text.hpp"
#include "../pieces/topmenu_charsel.hpp"

#define BODY_TYPE_IMG "images/body_types_image.jpg"

class CharacterSelectionScene : public kra::Scene {
private:
public:
    CharacterSelectionScene(sf::RenderWindow *_window);
    
protected:
    virtual void update(sf::RenderWindow &window, sf::Event &event) override;

private:
    void createText(sf::Vector2f winsize);
    void displayTopMenu();
    
};


#endif // SCENE_0_HPP