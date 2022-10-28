#ifndef DRAW
#define DRAW

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../Map.hpp"
#include "../World.hpp"

namespace Draw {

    void draw_map(sf::RenderWindow & window, const Map & map);
    void draw_backpack_menu(sf::RenderWindow & window, const World & world);
}

#endif