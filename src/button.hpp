#ifndef COMP_BUTTON_HPP
#define COMP_BUTTON_HPP

#include "utils.hpp"
#include "component.hpp"

namespace kra {
    class Button : public Component {
    private:
        sf::Texture but_tex;
        sf::Sprite but_spr;
    public:
        Button(const char *imgpath, sf::Vector2f size, sf::Vector2f pos)
        : Component(pos) {
            but_tex = utils::loadTexture(imgpath);
            but_spr.setTexture(but_tex);
            but_spr.setPosition(position);

            // Scale image to given size
            but_spr.setScale(
                size.x / but_spr.getLocalBounds().width,
                size.y / but_spr.getLocalBounds().height
            );
        }

        Button(const char *imgpath, sf::Vector2f size, float x, float y): Button(imgpath, size, sf::Vector2f(x, y)) {}

        virtual void update() override;
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    };
}

#endif // COMP_BUTTON_HPP