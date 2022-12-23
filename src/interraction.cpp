#include <vector>
#include <iostream>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "menu.hpp"
#include "backpack_menu.hpp"
#include "World.hpp"
#include "Map.hpp"

void World::game_interraction(sf::Event & event, sf::RenderWindow & window) {
    std::cout << "game interraction" << std::endl;
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::A : {
            //hero->move(-10, 0);
            wasd["A"] = PRESSED;
            break;
        }
        case sf::Keyboard::D : {
            // hero->move(10, 0);
            wasd["D"] = PRESSED;
            break;
        }
        case sf::Keyboard::W : {
            // hero->move(0, -10);
            wasd["W"] = PRESSED;
            break;
        }
        case sf::Keyboard::S : {
            // hero->move(0, 10);
            wasd["S"] = PRESSED;
            break;
        }
        case sf::Keyboard::F : {
            use_the_nearest_thing();
            break;
        }
        case sf::Keyboard::Escape: {
            this->mode = MENU;
            std::cout << "menu has been opened" << std::endl;
            // menu(window, *this);
            break;
        }
        case sf::Keyboard::Tab: {
            this->mode = BACKPACK_MENU;
            std::cout << "backpack menu has been opened" << std::endl;
            // backpack_menu(window, *this);
            break;
        }
        default:
            std::cout << "other event" << std::endl;
            break;
        }
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            std::cout << "LBM pressed" << std::endl;
            std::shared_ptr<Effect> eff = hero->use_weapon();
            eff->push_sound(0);
            all_effects.push_back(eff);
        }
    } else if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
        case sf::Keyboard::A : {
            wasd["A"] = RELEASED;
            break;
        }
        case sf::Keyboard::D : {
            wasd["D"] = RELEASED;
            break;
        }
        case sf::Keyboard::S : {
            wasd["S"] = RELEASED;
            break;
        }
        case sf::Keyboard::W : {
            wasd["W"] = RELEASED;
            break;
        }
        default:
            std::cout << "other event" << std::endl;
            break;
        }
    }
    // if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    //     std::cout << "LBM pressed" << std::endl;
    //     std::shared_ptr<Effect> eff = hero.use_weapon();
    //     all_effects.push_back(eff);
    // }
}
void World::menu_interraction(sf::Event & event, sf::RenderWindow & window) {
    switch (event.key.code) {
    case sf::Keyboard::Escape: {
        this->mode = RUN;
        std::cout << "menu has been closed" << std::endl;
        break;
    }
    
    default:
        break;
    }
}
void World::backpack_menu_interraction(sf::Event & event, sf::RenderWindow & window) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Tab: {
            this->mode = RUN;
            std::cout << "backpack menu has been closed" << std::endl;
            break;
        }
        
        default:
            break;
        }
    }
}

void World::message_menu_interraction(sf::Event & event, sf::RenderWindow & window) {
    switch (event.key.code) {
    case sf::Keyboard::Space: {
        this->mode = RUN;
        std::cout << "menu has been closed" << std::endl;
        break;
    }
    
    default:
        break;
    }
}