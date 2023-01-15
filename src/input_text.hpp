#ifndef INPUT_TEXT_HPP
#define INPUT_TEXT_HPP

#include "component.hpp"

namespace kra {
    class InputText : public Component {
    private:
        sf::String player_input;
        sf::Text player_text;
        bool is_active;
    public:
        InputText(sf::Vector2f pos);
        virtual void update(sf::RenderWindow &win, sf::Event &event) override;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };
}

#endif // INPUT_TEXT_HPP