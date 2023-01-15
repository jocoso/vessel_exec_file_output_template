#include "button.hpp"

kra::Button::Button(const sf::String name, sf::Vector2f pos):kra::Component(pos) {
    
    but_font.loadFromFile("arial.ttf");

    but_name.setString(name);
    but_name.setFont(but_font);
    but_name.setCharacterSize(10);
    but_name.setStyle(sf::Text::Bold);
    but_name.setFillColor(sf::Color::Black);

    //but_background_spr.setTexture(but_background_tex);

}

kra::Button::Button() : Button("", sf::Vector2f(0, 0)) {}
kra::Button::Button(sf::String name, float x, float y):Button(name, sf::Vector2f(x, y)) {}

void kra::Button::update(sf::RenderWindow &win, sf::Event &event) {
    
}

void kra::Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // target.draw(but_background_spr);
    target.draw(but_name);
}

void kra::Button::onClick(std::function<void()> _func) {
    on_click = _func;
}

