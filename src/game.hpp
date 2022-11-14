#ifndef GAME_MODE_HPP
#define GAME_MODE_HPP

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "GameWorld.hpp"

void game(sf::RenderWindow & window, World<GameTypeSystem> & world);

#endif