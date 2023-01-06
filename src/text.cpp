#include "text.hpp"

// TBD
void kra::Text::update(sf::RenderWindow &win) {}

void kra::Text::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text);
}

void kra::Text::setFont(const char *path) {
    if(!font.loadFromFile(path)) {
        std::cout << "Font couldn't be loaded\n";
        exit(-1);
    }
}

void kra::Text::setFillColor(sf::Color color) {
    text.setFillColor(color);
}

void kra::Text::setFont(sf::Font _font) {
    font = _font;
}