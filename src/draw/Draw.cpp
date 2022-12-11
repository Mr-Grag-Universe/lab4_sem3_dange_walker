#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Draw.hpp"
#include "../Map.hpp"

void Draw::draw_map(sf::RenderWindow & window, const Map & map) {
    // const std::vector <std::shared_ptr<GameObj> *> & at = map.get_all_things();
    // const sf::Sprite & hero_s = map.get_hero().get_sprite();
    // //const sf::Vector2f hero_pos = hero_s.getPosition();
    // //std::cout << "hero: (" << hero_pos.x << "; " << hero_pos.y << "); ";
    // //std::cout << "map: (" << map.get_W() << "; " << map.get_H() << "); ";
    // for (size_t i = 0, l = at.size(); i < l; ++i) {
    //     const sf::Sprite & s = (*at[i])->get_sprite();
    //     window.draw(s);
    // }

    // const std::vector <std::shared_ptr<NPC>> & npc = map.get_all_npcs();
    // for (size_t i = 0, l = npc.size(); i < l; ++i) {
    //     const sf::Sprite & s = npc[i]->get_sprite();
    //     window.draw(s);
    // }

    // const std::vector <std::shared_ptr<Effect>> & eff = map.get_all_effects();
    // for (size_t i = 0, l = eff.size(); i < l; ++i) {
    //     const sf::Sprite & s = eff[i]->get_sprite();
    //     window.draw(s);
    // }
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
    /*
    sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(map.get_W()/2, 0)),
            sf::Vertex(sf::Vector2f(map.get_W()/2, map.get_H()))
        };
    window.draw(line, 2, sf::Lines);*/

    // window.draw(hero_s);
}