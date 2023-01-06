#ifndef COMP_BUTTON_HPP
#define COMP_BUTTON_HPP

#include "component.hpp"

namespace kra {
    class Button : public Component {
    private:
        sf::CircleShape test;
    public:
        Button(sf::Vector2f pos)
        : Component(pos) {
            test.setRadius(150);
            test.setOutlineColor(sf::Color::Red);
            test.setOutlineThickness(5);
            test.setPosition(position);
        }

        Button(float x, float y)
        : Component(x, y) {
            test.setRadius(150);
            test.setOutlineColor(sf::Color::Red);
            test.setOutlineThickness(5);
            test.setPosition(position);
        }

        virtual void update() override;
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    };
}

#endif // COMP_BUTTON_HPP