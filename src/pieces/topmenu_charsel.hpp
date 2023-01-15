#ifndef TOPMENU_CHARSEL_HPP
#define TOPMENU_CHARSEL_HPP

#include "../component.hpp"
#include "../button.hpp"


class TopMenu : public kra::Component {
private:
    sf::RectangleShape bg;
    kra::Button btn;

public:
    TopMenu(sf::RenderWindow *_win, sf::Vector2f pos);
    TopMenu(sf::RenderWindow *_win, float x, float y);
    virtual void update(sf::RenderWindow &win, sf::Event &event) override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif // TOPMENU_CHARSEL_HPP