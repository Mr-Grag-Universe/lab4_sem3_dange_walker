#ifndef DRAW
#define DRAW

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../Map.hpp"

namespace Draw {

    void draw_map(sf::RenderWindow & window, const Map & map);

}

#endif