#ifndef UTILS_DAM_HPP
#define UTILS_DAM_HPP

#include "SFML/Graphics.hpp"
#include <iostream>

namespace utils {
    inline sf::Font loadFont(const char *path) {
        sf::Font font;

        if(!font.loadFromFile(path)) {
            std::cout << "Unable to load resource " << path << "\n";
            exit(-1);
        }

        return font;
    }

    inline sf::Texture loadTexture(const char *path) {
        sf::Texture tex;

        if(!tex.loadFromFile(path)) {
            std::cout << "Unable to load resource " << path << "\n";
            exit(-1);
        }

        return tex;
    }
}

#endif // UTILS_HPP