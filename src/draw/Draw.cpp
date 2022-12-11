#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Draw.hpp"
#include "../Map.hpp"

void Draw::draw_map(sf::RenderWindow & window, const Map & map) {
    const std::vector <std::shared_ptr<SFMLObject>> & ao = map.get_all_objs();
    for (auto o: ao) {
        o->draw(window);
        /*
        sf::Vertex l[] =
        {
            o->get_sprite().getPosition(),
            sf::Vertex(sf::Vector2f(o->get_sprite().getPosition().x + o->get_obj()->get_size().first, o->get_sprite().getPosition().y + o->get_obj()->get_size().second))
        };
        window.draw(l, 2, sf::Lines);*/
    }
}