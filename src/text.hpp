#ifndef COMP_TEXT_HPP
#define COMP_TEXT_HPP

#include <iostream>
#include <string>
#include "component.hpp"

namespace kra {
    class Text : public Component {
    private:
        sf::Text text;
        sf::Font font;
    public:
        Text(std::string content, sf::Vector2f pos) : 
            Component(pos) {
                setFont("arial.ttf");
                text.setFont(font);
                text.setString(content);
                text.setCharacterSize(50);
                text.setFillColor(sf::Color::White);
                text.setStyle(sf::Text::Bold);
                text.setPosition(position);
            }
        Text(const char *content, float x, float y) :
            Component(x, y) {
                sf::Font font;

                if(!font.loadFromFile("arial.ttf")) {
                    std::cout << "Font couldn't be loaded\n";
                    exit(-1);
                }

                text.setFont(font);
                text.setString(content);
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::White);
                text.setStyle(sf::Text::Bold);
            }

        void setFont(const char *path);
        virtual void update() override;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };
}

#endif // COMP_TEXT_HPP