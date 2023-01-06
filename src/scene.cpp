#include "scene.hpp"


kra::Scene::Scene(const char *path) {

    // Preparing image for rendering
    _bgtxre = loadTexture(path);
    _bgimg.setTexture(_bgtxre);

    _dimensions.x = _bgimg.getTexture()->getSize().x;
    _dimensions.y = _bgimg.getTexture()->getSize().y;
}

void kra::Scene::update(sf::RenderWindow &window) {
    window.draw(_bgimg);
}

sf::Vector2f kra::Scene::getSize() {
    return _dimensions;
}

sf::Sprite kra::Scene::getBackgroundImg() {
    return _bgimg;
}

sf::Texture kra::Scene::loadTexture(const char *filename) {
    sf::Texture txre;

    if(!txre.loadFromFile(filename)) {
        std::cout << "Couldn't Load Resource Image " << filename;
        exit(-1);
    }

    return txre;

}

kra::Scene::~Scene() {}