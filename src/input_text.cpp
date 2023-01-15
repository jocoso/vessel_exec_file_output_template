#include "input_text.hpp"
#include "utils.hpp"

kra::InputText::InputText(sf::Vector2f pos): Component(pos), is_active(false) {
    player_text.setPosition(pos);
    player_text.setFont(utils::loadFont("arial.ttf"));
    player_text.setFillColor(sf::Color::White);
    player_text.setCharacterSize(23);
    player_text.setString("hi"); // Default text
}

void kra::InputText::update(sf::RenderWindow &win, sf::Event &event) {
    if(event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Right) {
            auto mousePos = sf::Mouse::getPosition(win);
            auto translatedPos = win.mapPixelToCoords(mousePos);

            if(player_text.getGlobalBounds().contains(translatedPos))  {
                is_active = true;
            } else {
                is_active = false;
            }
        }
    }

    if(is_active) {
        if(event.type == sf::Event::TextEntered) {
            if(event.text.unicode < 128) {
                player_input += event.text.unicode;
                player_text.setString(player_input);
            }
        }
    }
}

void kra::InputText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(player_text);
}