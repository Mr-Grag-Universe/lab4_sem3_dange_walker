#ifndef INTERRACTION_HPP
#define INTERRACTION_HPP
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "menu.hpp"
#include "GameWorld.hpp"
#include "Map.hpp"

void game_interraction(sf::Event & event, sf::RenderWindow & window);
void menu_interraction(sf::Event & event, sf::RenderWindow & window);
void backpack_interraction(sf::Event & event, sf::RenderWindow & window);

#endif