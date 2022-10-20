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
    const sf::Sprite & hero_s = map.get_hero().get_sprite();
    const sf::Vector2f hero_pos = hero_s.getPosition();
    for (size_t i = 0, l = at.size(); i < l; ++i) {
        sf::Sprite & s = (*at[i])->get_sprite();
        sf::Vector2f s_window_pos = sf::Vector2f((float)(*at[i])->get_position().first, (float)(*at[i])->get_position().second);
        s_window_pos.x = map.get_W()/2 - (hero_pos.x - s_window_pos.x);
        s_window_pos.y = map.get_H()/2 - (hero_pos.y - s_window_pos.y);
        // std::cout << "hero: (" << hero_pos.x << "; " << hero_pos.y << "); ";
        // std::cout << "map: (" << map.get_W() << "; " << map.get_H() << "); ";
        // std::cout << "s_w: (" << s_window_pos.x << "; " << s_window_pos.y << ");\n";
        s.setPosition(s_window_pos);
        window.draw(s);
    }
    window.draw(hero_s);
}