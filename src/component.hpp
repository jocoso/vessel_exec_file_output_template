#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "SFML/Graphics.hpp"

namespace kra {
    class Component : public sf::Drawable {
    protected:
        sf::Vector2f position;
    public:
        Component(sf::Vector2f _position) : position(_position) {}
        Component(float x, float y) : position(x, y) {}
        virtual void update(sf::RenderWindow &win) = 0;
    };
}

#endif // COMPONENT_HPP