#ifndef COMP_BUTTON_HPP
#define COMP_BUTTON_HPP

#include <bits/stdc++.h>
#include "utils.hpp"
#include "component.hpp"

namespace kra {
    class InteractableImage : public Component  {
    private:
        sf::Texture but_tex;
        sf::Sprite but_spr;
        sf::Vector2f dimensions;
        std::function<void()> on_click = nullptr;
        bool is_pressed;
        float ratio_grow;
    public:
        // Single Images constructors
        InteractableImage(sf::Texture tex, sf::Vector2f size, sf::Vector2f pos)
        : Component(pos), ratio_grow(0.02f), is_pressed(false) {
            but_tex = tex;
            but_spr.setTexture(tex);

            but_spr.setTexture(but_tex);
            but_spr.setPosition(position);

            // Set Scale in size for image manipulation
            dimensions.x = size.x / but_spr.getLocalBounds().width;
            dimensions.y = size.y / but_spr.getLocalBounds().height;

            // Scale image to size
            but_spr.setScale(
                dimensions
            );
        }

        InteractableImage(sf::Sprite spr, sf::Texture tex, sf::Vector2f pos)
        : Component(pos), ratio_grow(0.02f), is_pressed(false) {
            but_spr = spr;
            but_tex = tex;
            but_spr.setTexture(but_tex);

            but_spr.setTexture(but_tex);
            but_spr.setPosition(position);

            dimensions.x = 1;
            dimensions.y = 1;

        }

        InteractableImage(sf::Texture tex, sf::Vector2f size, float x, float y): InteractableImage(tex, size, sf::Vector2f(x, y)) {}
        void setRatioGrow(float _ratio_grow);
        void onClick(std::function<void()> _func);
        virtual void update(sf::RenderWindow &win, sf::Event &event) override;
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void setSprite(sf::Sprite spr);
        void setTexture(sf::Texture tex);
    };
}

#endif // INTER_IMG_HPP