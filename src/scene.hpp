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
        sf::Event _event;
        std::vector<Component*> componentList;
    protected:
        sf::RenderWindow *window;
    public:
        Scene(const char *path, sf::RenderWindow *_window);
        void draw(sf::RenderWindow &window);
        sf::Sprite getBackgroundImg();
        void addComponent(Component *component);
        ~Scene();

    protected:
        virtual void update(sf::RenderWindow &window, sf::Event &event) {}; // Modifiable by inheritance 
        sf::Texture loadTexture(const char *filename);

    private:
        Scene();
    };

}

#endif // SCENE_HPP