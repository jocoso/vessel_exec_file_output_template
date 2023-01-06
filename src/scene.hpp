#ifndef SCENE_HPP
#define SCENE_HPP


#include <iostream>
#include "SFML/Graphics.hpp"

namespace kra {
    class Scene {
    private:
        sf::Vector2f _dimensions;
        sf::Sprite _bgimg;
        sf::Texture _bgtxre;
    public:
        Scene(const char *path);
        sf::Vector2f getSize();
        void update(sf::RenderWindow &window);
        sf::Sprite getBackgroundImg();
        ~Scene();

    protected:
        sf::Texture loadTexture(const char *filename);
    };
}

#endif // SCENE_HPP