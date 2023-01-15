#include "topmenu_charsel.hpp"

TopMenu::TopMenu(sf::RenderWindow *_win, sf::Vector2f _position) : kra::Component(_position) {
    bg.setPosition(this->position);
    bg.setSize(sf::Vector2f(_win->getSize().x, _win->getSize().y/10));
    bg.setOutlineThickness(5);
    bg.setFillColor(sf::Color::White);

    btn = kra::Button("Gender", sf::Vector2f(10, 10));

}

TopMenu::TopMenu(sf::RenderWindow *_win, float x, float y) : TopMenu(_win, sf::Vector2f(x, y)) {}

void TopMenu::update(sf::RenderWindow &win, sf::Event &event) {

}

void TopMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(bg);
    target.draw(btn);
}
