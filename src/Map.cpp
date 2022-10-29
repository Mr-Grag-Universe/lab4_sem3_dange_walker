#include "Map.hpp"

Map::Map(const World & w) : hero(w.get_hero()), W(w.get_W()), H(w.get_H()) {
    const std::vector <std::shared_ptr<Obj>> & at = w.get_all_things();
    // std::cout << "map_hero_position: (" << hero.get_position().first << ", " << hero.get_position().second << ")\n";
    for (size_t i = 0, l = at.size(); i < l; ++i) {
        std::pair <unsigned int, unsigned int> p = at[i]->get_position();
        if (distance(p, hero.get_position()) <= 1900) {
            all_things.push_back((std::shared_ptr<Obj> *) &at[i]);
            // const sf::Sprite & hero_s = hero.get_sprite();
            const sf::Vector2f hero_pos = sf::Vector2f((float) hero.get_position().first, (float) hero.get_position().second);
            sf::Vector2f s_window_pos = sf::Vector2f((float)at[i]->get_position().first, (float)at[i]->get_position().second);
            s_window_pos.x = W/2 - (hero_pos.x - s_window_pos.x);
            s_window_pos.y = H/2 - (hero_pos.y - s_window_pos.y);
            at[i]->set_sprite_position(std::make_pair(s_window_pos.x, s_window_pos.y));

            // std::cout << "hero: (" << hero_pos.x << "; " << hero_pos.y << "); ";
            // std::cout << "map: (" << W << "; " << H << "); ";
            // std::cout << "s_w: (" << s_window_pos.x << "; " << s_window_pos.y << ");\n";
            
            switch (at[i]->get_type()) {
                case FLOOR:
                    env.floor.push_back((std::shared_ptr<Floor> *) &at[i]);
                    break;
                case DOOR:
                    env.doors.push_back((std::shared_ptr<Door> *) &at[i]);
                    break;
                case WALL:
                    env.walls.push_back((std::shared_ptr<Wall> *) &at[i]);
                    break;
                default:
                    break;
            }
        }
    }
    const std::vector <std::shared_ptr<NPC>> & npc = w.get_all_npcs();
    for (size_t i = 0, l = npc.size(); i < l; ++i) {
        std::pair <unsigned int, unsigned int> p = npc[i]->get_position();
        if (distance(p, hero.get_position()) <= 1900) {
            all_npc.push_back((std::shared_ptr<NPC>) npc[i]);
            // const sf::Sprite & hero_s = hero.get_sprite();
            const sf::Vector2f hero_pos = sf::Vector2f((float) hero.get_position().first, (float) hero.get_position().second);
            sf::Vector2f s_window_pos = sf::Vector2f((float)npc[i]->get_position().first, (float)npc[i]->get_position().second);
            s_window_pos.x = W/2 - (hero_pos.x - s_window_pos.x);
            s_window_pos.y = H/2 - (hero_pos.y - s_window_pos.y);
            npc[i]->set_sprite_position(std::make_pair(s_window_pos.x, s_window_pos.y));
        }
    }
    // std::cout << "map hero position: (" << hero.get_sprite().getPosition().x << ", " << hero.get_position().second << ")\n";
}