#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

class Scene : public sf::RectangleShape {
public:
    Scene(const char *sceneName);
private:
    std::string scene_name;
    
};

#endif // SCENE_H