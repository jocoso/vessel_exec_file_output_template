#include "scene.hpp"


kra::Scene::Scene(sf::Image bgimg) {
    
    _dimensions.x = bgimg.getSize().x;
    _dimensions.y = bgimg.getSize().y;

    // Preparing image for rendering
    sf::Image img;
    img.create(_dimensions.x, _dimensions.y, sf::Color::Black);
    img.copy(bgimg, _dimensions.x/2, _dimensions.y/2);

    sf::Texture tx_img;
    tx_img.loadFromImage(img);
    _bgimg.setTexture(tx_img);
    
}

void kra::Scene::play(sf::RenderWindow &window) {
    window.draw(_bgimg);
}

sf::Vector2f kra::Scene::getSize() {
    return _dimensions;
}
