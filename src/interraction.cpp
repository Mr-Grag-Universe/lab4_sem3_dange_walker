#include <vector>
#include <iostream>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "backpack_menu.hpp"
#include "World.hpp"
#include "Map.hpp"

void World::game_interraction(sf::Event & event, sf::RenderWindow & window) {
    std::cout << "game interraction" << std::endl;
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::A : {
            hero.move(-10, 0);
            break;
        }
        case sf::Keyboard::D : {
            hero.move(10, 0);
            break;
        }
        case sf::Keyboard::W : {
            hero.move(0, -10);
            break;
        }
        case sf::Keyboard::S : {
            hero.move(0, 10);
            break;
        }
        case sf::Keyboard::Tab: {
            this->mode = MENU;
            std::cout << "menu has been opened" << std::endl;
            menu(window, *this);
            break;
        }
        default:
            std::cout << "other event" << std::endl;
            break;
        }
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            std::cout << "LBM pressed" << std::endl;
            hero.use_weapon(*this);
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::cout << "LBM pressed" << std::endl;
        hero.use_weapon(*this);
    }
}
void World::menu_interraction(sf::Event & event, sf::RenderWindow & window) {
    switch (event.key.code) {
    case sf::Keyboard::Tab: {
        this->mode = RUN;
        std::cout << "menu has been closed" << std::endl;
        break;
    }
    
    default:
        break;
    }
}