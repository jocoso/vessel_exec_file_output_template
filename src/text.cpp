#include "text.hpp"

kra::Text::Text(sf::String content, unsigned int position, sf::Vector2f winsize, float _y)
    :Component(sf::Vector2f(0, 0))
 {
    // Preparing generic text
    setFont("arial.ttf");
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    
    // CENTER
    float width = text.getLocalBounds().width / 2;
    //unsigned int size = width * content.getSize();
    text.setPosition(sf::Vector2f(
        (winsize.x / 2) - width,
        _y
    ));

}

// TBD
void kra::Text::update(sf::RenderWindow &win, sf::Event &event) {}

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