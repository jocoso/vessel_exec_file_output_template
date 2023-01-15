#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "component.hpp"
#include <bits/stdc++.h>
#include "utils.hpp"

namespace kra {
    class Button : public Component {
    private:
        sf::Texture but_background_tex;
        sf::Sprite but_background_spr;
        sf::Text but_name;
        sf::Font but_font;

        sf::Vector2f but_dimensions;
        std::function<void()> on_click = nullptr;
        bool but_is_pressed;
    public:
        Button();
        Button(sf::String name, sf::Vector2f pos);
        Button(sf::String name, float x, float y);
        virtual void update(sf::RenderWindow &win, sf::Event &event) override;
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
        void onClick(std::function<void()> _func);

        void setBackground(sf::Texture tex) { but_background_tex = tex; but_background_spr.setTexture(but_background_tex); }
        void setText(sf::String txt) { but_name.setString(txt); }
        void setText(sf::Text txt) { but_name = txt; }
        sf::Text getText() { return but_name; }
        sf::Texture getBackground() { return but_background_tex; }
    };
}

#endif  //BUTTON_HPP