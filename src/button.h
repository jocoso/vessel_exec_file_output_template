#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Thor/Shapes.hpp>
#include <Thor/Graphics.hpp>

#include "component.h"

namespace gui {
    namespace state {
        enum {
            NORMAL = 0,
            HOVERED = 1,
            CLICKED = 2
        };
    }

    class Button : public Component {
        private:
            // BACKGROUND
            sf::Color _bgNormal;        // Normal background color
            sf::Color _bgHover;         // Hovered background color
            sf::Color _bgClicked;       // Clicked background color

            // TEXT
            sf::Color _textNormal;      
            sf::Color _textHover;
            sf::Color _textClicked;

            // BORDER
            sf::Color _border;
            float _borderThickness;
            float _borderRadius;

            // CONFIG
            sf::Uint32 _btnstate;
            sf::ConvexShape _button;
            sf::Font _font;
            unsigned int _fontSize;
            sf::Text _text;
            sf::Text _shadow;

    public:
        Button(int id, sf::Vector2f dimensions, sf::Vector2f position, std::string s, sf::Font &f)
        : Component(id, dimensions, position) {
            
            _btnstate = gui::state::NORMAL;

            _textNormal = sf::Color(255,255,255);
            _textHover = sf::Color(255,255,255);
            _textClicked = sf::Color(255,255,255);
            _bgNormal = sf::Color(0,255,255,100);
            _bgHover = sf::Color(0,200,200,100);
            _bgClicked = sf::Color(0,150,150);
            _border = sf::Color(255,255,255,100);

            // Setting up text
            _text.setString(s);
            _text.setFont(f);
            _text.setOrigin(_text.getGlobalBounds().width/2, _text.getGlobalBounds().height/2);
            _text.setColor(_textNormal);

            _borderRadius = 5.f;
            _borderThickness = 0.f;
            _dimensions = sf::Vector2f(_text.getGlobalBounds().width * 1.5f, _text.getGlobalBounds().height * 1.5f );

            _button = thor::Shapes::roundedRect(_dimensions, _borderRadius, _bgNormal, _borderThickness, _border);
            _button.setOrigin(_button.getGlobalBounds().width/2, _button.getGlobalBounds().height/2);
            _button.setPosition(_position);

            sf::Vector2f textPosition = sf::Vector2f(_button.getPosition().x, _button.getPosition().y - _button.getGlobalBounds().height/4);
            _text.setPosition(textPosition);

            _shadow.setFont(f);
            _shadow = _text;
            _shadow.setOrigin(_shadow.getGlobalBounds().width/2, _shadow.getGlobalBounds().height/2);
            _shadow.setPosition(_text.getPosition().x + 3.f, _text.getPosition().y + 3.f);

        }

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override; 
        virtual void update(sf::Event& e, sf::RenderWindow& window) override;

        ~Button();
    };
}


#endif // BUTTON_H