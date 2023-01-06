#ifndef SCENE_HPP
#define SCENE_HPP


#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "component.hpp"

namespace kra {
    class Scene {
    private:
        // BACKGROUND
        sf::Sprite _bgimg;
        sf::Texture _bgtxre;
        std::vector<Component*> componentList;
    public:
        Scene(const char *path, const sf::Vector2f dim);
        void update(sf::RenderWindow &window);
        sf::Sprite getBackgroundImg();
        void addComponent(Component *component);
        ~Scene();

    protected:
        sf::Texture loadTexture(const char *filename);
    
    private:
        Scene();
    };
}

#endif // SCENE_HPP