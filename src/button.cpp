#include "button.hpp"

void kra::Button::update(sf::RenderWindow &win) {
    auto mouse_pos = sf::Mouse::getPosition(win); 
    auto translated_pos = win.mapPixelToCoords(mouse_pos);

    // Mouse is colliding with object
    if(but_spr.getGlobalBounds().contains(translated_pos)) {
        // std::cout << "Colliding\n";
        // Make the image bigger default 0.02 times bigger
        but_spr.setScale(
            dimensions.x + ratio_grow,
            dimensions.y + ratio_grow
        );
        // Mouse clicks
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !is_pressed) {

            is_pressed = true;
            // Call onclick if the function is there
            if(on_click != nullptr) 
                on_click();
            
            // No double clicks
        } else if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && is_pressed) { 
            is_pressed = false;
        }

    } else { // No longer colliding
        // Set image to original size
        but_spr.setScale(
            dimensions.x,
            dimensions.y
        );
    }
}

void kra::Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(but_spr);
}

void kra::Button::onClick(void (*function)(void)) {
    on_click = function;
}

// set a ratio between 0 and 1
// It will scale the image to that ratio by adding the ratio to the
// previous ratio. It is recommended to use small float numbers
// 0.01 0.02 instead of 1 or 0.5 as it will make the image obsenely big
void kra::Button::setRatioGrow(float _ratio_grow) {
    ratio_grow = _ratio_grow;
}
