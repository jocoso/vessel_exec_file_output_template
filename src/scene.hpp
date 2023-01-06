#ifndef SCENE_HPP
#define SCENE_HPP


#include <iostream>
#include "SFML/Graphics.hpp"

namespace kra {
    class Scene {
    private:
        // BACKGROUND
        sf::Sprite _bgimg;
        sf::Texture _bgtxre;
    public:
        Scene(const char *path, const sf::Vector2f dim);
        void update(sf::RenderWindow &window);
        sf::Sprite getBackgroundImg();
        ~Scene();

    protected:
        sf::Texture loadTexture(const char *filename);
    
    private:
        Scene();
    };
}

#endif // SCENE_HPP