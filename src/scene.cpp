#include "scene.hpp"


kra::Scene::Scene(const char *path, const sf::Vector2f dim) {

    // Preparing image for rendering

    // XXX: Sprite requires an existing copy of the texture
    // to be present in the memory while in use.
    _bgtxre = loadTexture(path);
    _bgimg.setTexture(_bgtxre);

    // Scale image to given screen dimensions
    _bgimg.setScale(
        dim.x / _bgimg.getLocalBounds().width,
        dim.y / _bgimg.getLocalBounds().height
    );
}

void kra::Scene::update(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);
    window.draw(_bgimg);

    for(auto component: componentList) {
        component->update(window);
        window.draw(*component);
    }

    window.display();
}

sf::Sprite kra::Scene::getBackgroundImg() {
    return _bgimg;
}

void kra::Scene::addComponent(kra::Component *component) {
    componentList.push_back(component);
}

sf::Texture kra::Scene::loadTexture(const char *filename) {
    sf::Texture txre;

    // Making sure the texture exists in file
    if(!txre.loadFromFile(filename)) {
        std::cout << "Couldn't Load Resource Image " << filename;
        exit(-1);
    }

    return txre;

}

kra::Scene::~Scene() {
    for(auto component: componentList) {
        free(component);
    }
}