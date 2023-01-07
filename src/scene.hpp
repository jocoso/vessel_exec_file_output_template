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
        sf::RenderWindow *window;
    public:
        Scene(const char *path, sf::RenderWindow *_window);
        void draw(sf::RenderWindow &window);
        sf::Sprite getBackgroundImg();
        void addComponent(Component *component);
        ~Scene();

    protected:
        void init(sf::RenderWindow &window) {} // Modifiable by inheritance
        void update(sf::RenderWindow &window) {} // Modifiable by inheritance 
        sf::Texture loadTexture(const char *filename);
    
    private:
        Scene();
    };

}

#endif // SCENE_HPP