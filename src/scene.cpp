#include "scene.h"

Scene::Scene(const char *sceneName) {
    sf::Vector2f size(100, 50);
    this->setSize(size);
    this->setFillColor(sf::Color::Red);
}