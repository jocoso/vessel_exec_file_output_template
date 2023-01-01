#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>

// Components will all inherit from this class.
class Component : public sf::Drawable{
    
protected:
    int             _id;
    sf::Vector2f    _dimensions;
    sf::Vector2f    _position;

    Component(int id, sf::Vector2f dimensions, sf::Vector2f position) {
        _id = id;
        _dimensions = dimensions;
        _position   = position;
    };
    
    virtual void update(sf::Event& e, sf::RenderWindow& window) = 0;

    void setPosition(sf::Vector2f position) {_position = position;};  
    void setDimensions(sf::Vector2f dimensions) {_dimensions = dimensions;}; 
};

#endif //COMPONENT_H