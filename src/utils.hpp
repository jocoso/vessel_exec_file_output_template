#ifndef UTILS_HPP
#define UTILS_HPP

#include "SFML/Graphics.hpp"
#include <iostream>

namespace utils {
    extern sf::Font loadFont(const char *path) {
        sf::Font font;

        if(!font.loadFromFile(path)) {
            std::cout << "Unable to load resource " << path << "\n";
            exit(-1);
        }

        return font;
    }
}

#endif // UTILS_HPP