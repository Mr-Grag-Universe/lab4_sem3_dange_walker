#ifndef DRAW_BACKPACK_MENU_HPP
#define DRAW_BACKPACK_MENU_HPP

#include <SFML/Window.hpp>

#include "../World.hpp"
#include "BackPackMenu.hpp"

namespace Draw {
    void draw_char_backpack(sf::RenderWindow & window, const BackPackMenu & BPMenu);
    void draw_container(sf::RenderWindow & window, const BackPackMenu & BPMenu);
}

#endif // DRAW_BACKPACK_MENU_HPP