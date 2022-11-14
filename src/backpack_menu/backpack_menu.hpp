#ifndef BACK_PACK_MENU_MODE_HPP
#define BACK_PACK_MENU_MODE_HPP

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "World.hpp"
#include "MenuObj.hpp"

void backpack_menu(sf::RenderWindow & window, World & world);
std::vector <MenuObj> load_menu_objects();

#endif // BACK_PACK_MENU_MODE_HPP