#ifndef COMP_TEXT_HPP
#define COMP_TEXT_HPP

#include <iostream>
#include <string>
#include "component.hpp"

namespace kra {
    enum Position {
        LEFT=0,
        CENTER=0,
        RIGHT=0
    };

    class Text : public Component {
    private:
        sf::Text text;
        sf::Font font;
    public:
        Text(std::string content, sf::Vector2f pos) : 
            Component(pos) {

                // Preparing generic text
                setFont("arial.ttf");
                text.setFont(font);
                text.setString(content);
                text.setCharacterSize(50);
                text.setFillColor(sf::Color::White);
                text.setStyle(sf::Text::Bold);
                text.setPosition(position);
            }

        

        // Delegating constructor
        Text(const char *content, float x, float y) : Text(content, sf::Vector2f(x, y)) {}
        Text(sf::String content, unsigned int position, sf::Vector2f winsize, float _y);

        void setFont(const char *path);
        void setFont(sf::Font _font);
        void setFillColor(sf::Color color);
        virtual void update(sf::RenderWindow &win, sf::Event &event) override;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };
}

#endif // COMP_TEXT_HPP