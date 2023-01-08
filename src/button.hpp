#ifndef COMP_BUTTON_HPP
#define COMP_BUTTON_HPP

#include <bits/stdc++.h>
#include "utils.hpp"
#include "component.hpp"

namespace kra {
    class Button : public Component  {
    private:
        sf::Texture but_tex;
        sf::Sprite but_spr;
        sf::Vector2f dimensions;
        std::function<void()> on_click = nullptr;
        bool is_pressed;
        float ratio_grow;
    public:
        Button(const char *imgpath, sf::Vector2f size, sf::Vector2f pos)
        : Component(pos), ratio_grow(0.02f), is_pressed(false) {
            but_tex = utils::loadTexture(imgpath);
            but_spr.setTexture(but_tex);
            but_spr.setPosition(position);

            // Set scale in size for image manipulation
            size.x = size.x / but_spr.getLocalBounds().width;
            size.y = size.y / but_spr.getLocalBounds().height;

            // Scale image to given size
            but_spr.setScale(
                size.x,
                size.y
            );

            dimensions = size;
        }

        Button(const char *imgpath, sf::Vector2f size, float x, float y): Button(imgpath, size, sf::Vector2f(x, y)) {}
        void setRatioGrow(float _ratio_grow);
        void onClick(void (*function)(void));
        virtual void update(sf::RenderWindow &win) override;
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    };
}

#endif // COMP_BUTTON_HPP