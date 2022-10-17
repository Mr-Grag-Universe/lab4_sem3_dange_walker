#include <iostream>
// #include <GLFW/glfw3.h>
// #include <GLFW/glfw3native.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Draw.hpp"
#include "../Map.hpp"

void Draw::draw_map(sf::RenderWindow & window, const Map & map) {
    const std::vector <std::unique_ptr<Obj> *> & at = map.get_all_things();
    for (size_t i = 0, l = at.size(); i < l; ++i) {
        // std::cout << (*at[i])->get_name() << std::endl;
        const sf::Sprite & s = (*at[i])->get_sprite();
        std::cout << s.getPosition().x << s.getPosition().y << "scale: " << s.getScale().x << s.getScale().y << std::endl;
        window.draw(s);
    }
}