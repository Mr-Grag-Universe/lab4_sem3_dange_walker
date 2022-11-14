#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "draw_backpack_menu.hpp"
#include "constants.hpp"


void Draw::draw_char_backpack(sf::RenderWindow & window, const Character & ch) {
    window.clear(MyDarkSlateGray);
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setPosition(sf::Vector2f(120, 50));
    window.draw(rectangle);

    std::cout << "your char backpack";
}

void Draw::draw_container(sf::RenderWindow & window, const Container & container) {
    std::cout << "hi";
}