#include "text.hpp"

void kra::Text::update() {}
void kra::Text::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text);
}

void kra::Text::setFont(const char *path) {
    if(!font.loadFromFile(path)) {
        std::cout << "Font couldn't be loaded\n";
        exit(-1);
    }
}