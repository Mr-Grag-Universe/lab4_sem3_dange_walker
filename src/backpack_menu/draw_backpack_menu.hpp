#ifndef DRAW_BACKPACK_MENU_HPP
#define DRAW_BACKPACK_MENU_HPP

#include <SFML/Window.hpp>

#include "../World.hpp"

namespace Draw {
    void draw_char_backpack(sf::RenderWindow & window, const Character & );
    void draw_container(sf::RenderWindow & window, const Container & container);
}

#endif // DRAW_BACKPACK_MENU_HPP