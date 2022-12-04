#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "draw_backpack_menu.hpp"
#include "constants.hpp"
#include "BackPackMenu.hpp"
#include "BPMObject.hpp"


void Draw::draw_char_backpack(sf::RenderWindow & window, const BackPackMenu & BPMenu) {
    window.clear(msc::MyDarkSlateGray);
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setPosition(sf::Vector2f(120, 50));
    window.draw(rectangle);

    const std::vector <std::shared_ptr<BPMObj>> & all_menu_fields = BPMenu.get_all_menu_fields();
    for (auto field : all_menu_fields) {
        field->draw(window);
    }

    std::cout << "your char backpack";
}

void Draw::draw_container(sf::RenderWindow & window, const BackPackMenu & BPMenu) {
    std::cout << "hi";
}