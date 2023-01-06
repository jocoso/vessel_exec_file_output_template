#ifndef SCENE_HPP
#define SCENE_HPP

#include "SFML/Graphics.hpp"

namespace kra {
    class Scene {
    private:
        sf::Vector2f _dimensions;
        sf::Sprite _bgimg;
    public:
        Scene(sf::Image bgimg);
        sf::Vector2f getSize();
        void play(sf::RenderWindow &window);
    };
}

#endif // SCENE_HPP