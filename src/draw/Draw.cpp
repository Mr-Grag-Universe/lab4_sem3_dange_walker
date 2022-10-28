#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Draw.hpp"
#include "../Map.hpp"

void Draw::draw_map(sf::RenderWindow & window, const Map & map) {
    const std::vector <std::shared_ptr<Obj> *> & at = map.get_all_things();
    const sf::Sprite & hero_s = map.get_hero().get_sprite();
    //const sf::Vector2f hero_pos = hero_s.getPosition();
    //std::cout << "hero: (" << hero_pos.x << "; " << hero_pos.y << "); ";
    //std::cout << "map: (" << map.get_W() << "; " << map.get_H() << "); ";
    for (size_t i = 0, l = at.size(); i < l; ++i) {
        const sf::Sprite & s = (*at[i])->get_sprite();
        window.draw(s);
    }
    window.draw(hero_s);
}

void Draw::draw_backpack_menu(sf::RenderWindow & window, const World & world) {
    std::cout << "hi";
}