#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "menu.hpp"
#include "backpack_menu.hpp"
#include "Map.hpp"
#include "Object.hpp"
#include "constants.hpp"
#include "containers/Box.hpp"
#include "containers/Chest.hpp"
#include "weapon/Sward.hpp"
#include "World.hpp"

World::World(const std::string &file_name) : World()
{
    this->all_things = load_things_from_file(file_name);
    for (size_t i = 0, l = all_things.size(); i < l; ++i)
    {
        switch (all_things[i]->get_type())
        {
        case FLOOR:
            env.floor.push_back((std::shared_ptr<Floor> *)&all_things[i]);
            break;
        case DOOR:
            env.doors.push_back((std::shared_ptr<Door> *)&all_things[i]);
            break;
        case WALL:
            env.walls.push_back((std::shared_ptr<Wall> *)&all_things[i]);
            break;
        default:
            break;
        }
    }
}

World::World(std::vector<std::shared_ptr<GameObj>> things) : World()
{
    all_things = std::move(things);
}

std::shared_ptr<GameObj> World::load_object(std::string type, std::ifstream &file)
{
    std::shared_ptr<GameObj> obj;
    switch (types[type])
    {
    case FLOOR:
    {
        obj = std::make_shared<Floor>();
        break;
    }
    case DOOR:
    {
        obj = std::make_shared<Door>();
        break;
    }
    case WALL:
        obj = std::make_shared<Wall>();
        break;
    case CHEST:
    {
        obj = std::make_shared<Chest>();
        break;
    }
    case SWARD:
    {
        obj = std::make_shared<Sward>();
        break;
    }
    case SLIME:
        obj = std::make_shared<Slime>();
        break;
    case SKELETON:
        obj = std::make_shared<Skeleton>();
    case SIDOROVICH:
        obj = std::make_shared<Sidorovich>();
    default:
        break;
    }
    obj->read(file);
    return obj;
}

std::shared_ptr<NPC> World::load_npc(std::string type, std::ifstream &file)
{
    std::shared_ptr<NPC> obj;
    switch (types[type])
    {
    case SLIME:
        obj = std::make_shared<Slime>();
        break;
    case SKELETON:
        obj = std::make_shared<Skeleton>();
        break;
    case SIDOROVICH:
        obj = std::make_shared<Sidorovich>();
        break;
    default:
        break;
    }
    obj->read(file);
    return obj;
}

std::vector<std::shared_ptr<GameObj>> World::load_things_from_file(const std::string &file_name)
{
    std::cout << "#=#=#=#=# opening fstream with \"" << file_name << "\" file..." << std::endl;
    std::ifstream file(file_name);
    if (!file)
    {
        std::cout << "cannot find this file: " << file_name << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }

    std::string type;
    std::vector<std::shared_ptr<GameObj>> v;
    while (file >> type)
    {
        if (type.substr(0, 2) == "//")
        {
            std::cout << type << "\n";
            continue;
        }
        std::cout << "object type: " << type << "\n";
        v.push_back(load_object(type, file));
    }

    file.close();

    return v;
}

std::vector<std::shared_ptr<NPC>> World::load_npcs_from_file(const std::string &file_name)
{
    std::cout << "#=#=#=#=# opening fstream with \"" << file_name << "\" file..." << std::endl;
    std::ifstream file(file_name);
    if (!file)
    {
        std::cout << "cannot find this file: " << file_name << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }

    std::string type;
    std::vector<std::shared_ptr<NPC>> v;
    while (file >> type)
    {
        if (type.substr(0, 2) == "//")
        {
            std::cout << type << "\n";
            continue;
        }
        std::cout << "npc type: " << type << "\n";
        if (alive_types.find(types[type]) != alive_types.end())
            v.push_back(load_npc(type, file));
        else
            throw std::runtime_error("this is not npc in file: " + file_name);
    }

    file.close();

    return v;
}

std::map<GameTypeSystem, ObjTextureStore> World::load_game_obj_textures_from_file(const std::string &file_name)
{
    std::cout << "#=#=#=#=# opening fstream with \"" << file_name << "\" file..." << std::endl;
    std::ifstream file(file_name);
    if (!file)
    {
        std::cout << "cannot find this file: " << file_name << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }

    std::string type;
    std::string texture_type;
    std::map<GameTypeSystem, ObjTextureStore> T;
    fs::path file_path;
    size_t number{};
    size_t x_in{}, y_in{};
    size_t width{}, height{};
    double n_repeat_x{}, n_repeat_y{};
    while (file >> type)
    {
        for (short i = 0; i < 5; ++i)
        {
            file >> texture_type;
            if (texture_type == "//")
                continue;
            if (texture_type.substr(0, 2) == "//")
            {
                std::cout << texture_type << "\n";
                continue;
            }
            if (texture_type == "textures")
            {
                file >> number;
                std::cout << "game obj type: " << type << "\n";
                if (true || effect_types.find(types[type]) == effect_types.end())
                {
                    for (size_t i = 0; i < number; ++i)
                    {
                        file >> x_in >> y_in;
                        file >> width >> height;
                        file >> n_repeat_x >> n_repeat_y;
                        // std::(file, file_path);
                        file >> file_path;
                        T[types[type]].textures.push_back(std::make_shared<sf::Texture>());
                        sf::Vector2 position_in((int)x_in, (int)y_in);
                        sf::Vector2 size_f((float)(width * n_repeat_x), (float)(height * n_repeat_y));
                        sf::Vector2 size_i((int)(width), (int)(height));
                        sf::Vector2 size_r((int)(width * n_repeat_x), (int)(height * n_repeat_y));
                        if (!T[types[type]].textures[i]->loadFromFile(mp::img / file_path, sf::IntRect(position_in, size_i)))
                        {
                            std::cout << "cannot read texture from file : " << file_path << std::endl;
                            throw std::invalid_argument("there is not such file with texture");
                        }
                    }
                }
                else
                    throw std::runtime_error("this is not game obj in file: " + file_name);
            }
            else if (texture_type == "preview")
            {
                file >> x_in >> y_in;
                file >> width >> height;
                file >> n_repeat_x >> n_repeat_y;
                // std::(file, file_path);
                file >> file_path;
                T[types[type]].preview = std::make_shared<sf::Texture>();
                sf::Vector2 position_in((int)x_in, (int)y_in);
                sf::Vector2 size_f((float)(width * n_repeat_x), (float)(height * n_repeat_y));
                sf::Vector2 size_i((int)(width), (int)(height));
                sf::Vector2 size_r((int)(width * n_repeat_x), (int)(height * n_repeat_y));
                if (!T[types[type]].preview->loadFromFile(mp::img / file_path, sf::IntRect(position_in, size_i)))
                {
                    std::cout << "cannot read texture from file : " << file_path << std::endl;
                    throw std::invalid_argument("there is not such file with texture");
                }
            }
            else if (texture_type == "backpack")
            {
                file >> x_in >> y_in;
                file >> width >> height;
                file >> n_repeat_x >> n_repeat_y;
                // std::(file, file_path);
                file >> file_path;
                T[types[type]].bp_texture = std::make_shared<sf::Texture>();
                sf::Vector2 position_in((int)x_in, (int)y_in);
                sf::Vector2 size_f((float)(width * n_repeat_x), (float)(height * n_repeat_y));
                sf::Vector2 size_i((int)(width), (int)(height));
                sf::Vector2 size_r((int)(width * n_repeat_x), (int)(height * n_repeat_y));
                if (!T[types[type]].bp_texture->loadFromFile(mp::img / file_path, sf::IntRect(position_in, size_i)))
                {
                    std::cout << "cannot read texture from file : " << file_path << std::endl;
                    throw std::invalid_argument("there is not such file with texture");
                }
            }
            else if (texture_type == "timing")
            {
                std::string period_s, life_time_s;
                file >> period_s;
                if (period_s == "static") {
                    std::cout << "this obj is static";
                    T[types[type]].is_static = true;
                    continue;
                }
                T[types[type]].is_static = false;
                file >> life_time_s;
                sf::Time period;
                sf::Time life_time;
                try
                {
                    period = stotime(period_s);
                    life_time = stotime(life_time_s);
                }
                catch (std::invalid_argument &ia)
                {
                    std::cout << ia.what();
                    throw;
                }
                catch (...)
                {
                    std::cout << "invalid time format may be occured";
                    throw std::runtime_error("invalid time format may be occured");
                }
                T[types[type]].standard_life_time = life_time;
                T[types[type]].standard_period = period;
            }
            else if (texture_type == "sounds")
            {
                std::string src_file;
                file >> src_file;
                T[types[type]].sounds.push_back(std::make_shared<sf::SoundBuffer>());
                // возможно не с той стороны смотрю
                if (!T[types[type]].sounds.front()->loadFromFile(mp::sound / src_file))
                {
                    std::cout << "cannot load this sound" << std::endl;
                    throw std::runtime_error("cannot read sound from file");
                }
            }
            else
            {
                throw std::runtime_error("cannot initializate this tipe of textures");
            }
        }
    }

    file.close();

    return T;
}

void World::add_character(const std::string &file_name)
{
    if (file_name.empty())
    {
        std::cout << "empty name of file with char sprite" << std::endl;
        throw std::invalid_argument("file does not exist");
    }
    std::ifstream file;
    file.open(file_name);
    hero->read(file);
    hero->set_position(std::make_pair(W / 2, H / 2));
    // size_t width = hero.get_texture()->getSize().x;
    // size_t height = hero.get_texture()->getSize().y;
    // hero.set_sprite_position(std::make_pair((W - width)/2, (H - height)/2));
    std::cout << "initial hero position: (" << hero->get_position().first << ", " << hero->get_position().second << ")\n";
    // std::cout << "initial hero sprite position: (" << hero.get_sprite().getPosition().x << ", " << hero.get_sprite().getPosition().y << ")\n";

    file.close();
}

void World::interraction(sf::Event &event, sf::RenderWindow &window)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
    {
        if (this->mode == RUN)
        {
            game_interraction(event, window);
        }
        else if (this->mode == MENU)
        {
            menu_interraction(event, window);
        }
        else if (this->mode == BACKPACK_MENU)
        {
            backpack_menu_interraction(event, window);
        }

        break;
    }
    case sf::Event::KeyReleased:
    {
        if (this->mode == RUN)
        {
            game_interraction(event, window);
        }
        else if (this->mode == MENU)
        {
            menu_interraction(event, window);
        }
        else if (this->mode == BACKPACK_MENU)
        {
            backpack_menu_interraction(event, window);
        }

        break;
    }
    case sf::Event::Resized:
    {
        W = event.size.width;
        H = event.size.height;
        // hero.set_sprite_position(std::make_pair((W-hero.get_texture()->getSize().x)/2, (H-hero.get_texture()->getSize().y)/2));
        std::cout << "new width: " << event.size.width << std::endl;
        std::cout << "new height: " << event.size.height << std::endl;
        break;
    }
    case sf::Event::MouseButtonPressed:
    {
        if (this->mode == RUN)
        {
            game_interraction(event, window);
        }
        else if (this->mode == MENU)
        {
            menu_interraction(event, window);
        }
        else if (this->mode == BACKPACK_MENU)
        {
            backpack_menu_interraction(event, window);
        }

        break;
    }
    default:
        break;
    }
    return;
}

void World::iterate() {
    // std::pair<unsigned int, unsigned int> p_h = hero->get_position();
    for (size_t i = 0; i < all_npc.size(); ++i) {
        all_npc[i]->iterate(*this);
    }

    for (size_t i = 0; i < all_npc.size(); ++i) {
        if (all_npc[i]->is_mobile()) {
            double v = all_npc[i]->get_velocity();
            if (v == 0)
                continue;
            double a = all_npc[i]->get_v_angle();
            int v_x = v * cos(a);
            int v_y = v * sin(a);
            all_npc[i]->move(v_x, v_y);
        }
    }

    for (size_t i = 0; i < all_effects.size(); ++i) {
        all_effects[i]->iterate();
    }

    for (size_t i = 0; i < all_effects.size(); ++i)
    {
        if (all_effects[i]->makes_damage())
        {
            for (size_t j = 0; j < all_npc.size(); ++j)
            {
                if (&all_effects[i]->get_originator_ptr() != &(*all_npc[j]))
                {
                    all_effects[i]->make_damage(*(all_npc[j]));
                    if (all_npc[j]->get_helth() == 0)
                    {
                        std::cout << all_npc[j]->get_name() << "has been killed" << std::endl;
                        int exp = all_npc[j]->get_exp_for_kill();
                        std::cout << "+ " << exp << " exp points have been collected" << std::endl;
                        hero->plus_exp(exp);
                        all_npc.erase(all_npc.begin() + j);
                        j--;
                    }
                }
            }
        }
        if (!all_effects[i]->exist()) {
            all_effects.erase(all_effects.begin() + i);
            i--;
        }
    }
    for (auto & key : wasd) {
        if (key.second == PRESSED) {
            if (key.first == "A") {
                hero->move(-3, 0);
                // std::cout << "A-moving\n";
            } else if (key.first == "D") {
                hero->move(3, 0);
                // std::cout << "D-moving\n";
            } else if (key.first == "S") {
                hero->move(0, 3);
                // std::cout << "S-moving\n";
            } else if (key.first == "W") {
                hero->move(0, -3);
                // std::cout << "W-moving\n";
            } else {
                std::cout << "unnown command\n";
                throw std::invalid_argument("unnown key has been pressed");
            }
        }
    }

    if (hero->get_helth() <= 0) {
        std::cout << "you dead!" << std::endl;
        hero->set_health(100);
    }

    return;
}

void World::add_things_from_file(const std::string &file_name)
{
    std::vector<std::shared_ptr<GameObj>> things = load_things_from_file(file_name);

    size_t old_len = all_things.size();
    all_things.insert(
        all_things.end(),
        std::make_move_iterator(things.begin()),
        std::make_move_iterator(things.end())
    );

    for (size_t i = 0, l = things.size(); i < l; ++i)
    {
        switch (all_things[old_len + i]->get_type())
        {
        case FLOOR:
            env.floor.push_back((std::shared_ptr<Floor> *)&all_things[old_len + i]);
            break;
        case DOOR:
            env.doors.push_back((std::shared_ptr<Door> *)&all_things[old_len + i]);
            break;
        case WALL:
            env.walls.push_back((std::shared_ptr<Wall> *)&all_things[old_len + i]);
            break;
        default:
            break;
        }
    }
}

void World::add_npcs_from_file(const std::string &file_name)
{
    std::vector<std::shared_ptr<NPC>> npcs = load_npcs_from_file(file_name);

    all_npc.insert(
        all_npc.end(),
        std::make_move_iterator(npcs.begin()),
        std::make_move_iterator(npcs.end()));
}

void World::add_game_obj_textures_from_file(const std::string &file_name)
{
    try
    {
        game_obj_textures = load_game_obj_textures_from_file(file_name);
    }
    catch (const std::runtime_error &re)
    {
        std::cout << re.what() << std::endl;
        std::cout << "cannot read obj textures from " << file_name << std::endl;
        throw std::runtime_error("cannot read obj textures from this file");
    }
}

void World::use_the_nearest_thing()
{
    std::cout << "thing interraction detected" << std::endl;
    std::shared_ptr<GameObj> nearest_obj;
    double min_dist = W;
    for (size_t i = 0, l = all_things.size(); i < l; ++i)
    {
        if (std::find(interractive_objs.begin(), interractive_objs.end(), all_things[i]->get_type()) != interractive_objs.end())
        {
            double d = distance(all_things[i]->get_position(), hero->get_position());
            if (d < min_dist)
            {
                min_dist = d;
                nearest_obj = all_things[i];
            }
        }
    }
    std::cout << "nearest obg name: " << nearest_obj->get_name() << std::endl;
    if (min_dist < 100)
    {
        std::cout << "we can interract with this object!" << std::endl;
        if (std::find(i_containers.begin(), i_containers.end(), nearest_obj->get_type()) != i_containers.end())
        {
            std::shared_ptr<Box> box = std::dynamic_pointer_cast<Box>(nearest_obj);
            hero->get_backpack().add(box->extract_all());
            std::cout << "all things from this container have been put to char's backpack" << std::endl;
        }
    }
    else
    {
        std::cout << "there is not interraction objects near enough" << std::endl;
    }
}