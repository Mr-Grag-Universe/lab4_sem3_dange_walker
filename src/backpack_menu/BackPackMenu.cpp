#include "BackPackMenu.hpp"
#include "BackPackStore.hpp"
#include "../constants.hpp"
#include <SFML/Graphics.hpp>

std::shared_ptr<BPMObj> use_constructor(BackPackTypeSystem type, std::string name, pair_ui64_t p, Container & c) {
    switch (type) {
    case SKIN:
        return std::make_shared<Skin>(name, p);
        break;
    case WEAPON_IN_ARMS:
        return std::make_shared<WeaponInArm>(name, p);
    case BACK_PACK_STORE:
        return std::make_shared<BackPackStore>(c);
    default:
        break;
    }
    return nullptr;
} 

// sf::Texture choose() {}

BackPackMenu::BackPackMenu(Character & c) : container(c.get_backpack()) {
    textures = load_textures(static_path / "bp_menu_textures.txt");

    std::ifstream file(static_path / fs::path("bp_menu.txt"));
    
    std::string type;
    pair_ui64_t p;
    pair_ui64_t size;
    bool need_texture = false;
    while(file >> type) {
        file >> p.first >> p.second;
        file >> size.first >> size.second;
        file >> need_texture;
        BackPackTypeSystem r_type = bp_menu_types[type];
        std::shared_ptr<BPMObj> field = use_constructor(r_type, type, p, c.get_backpack());
        if (need_texture) {
            std::shared_ptr <sf::Texture> t = textures[r_type].textures[0];
            field->set_texture(t, size);
            field->set_sprite_position(calculate_sprite_position(size, p));
        }

        all_menu_fields.push_back(field);
        switch (r_type) {
        case SKIN: {
            skin = std::dynamic_pointer_cast<Skin>(field);
            break;
        }
        case WEAPON_IN_ARMS:
            weapon = std::dynamic_pointer_cast<WeaponInArm>(field);
            break;
        case BACK_PACK_STORE:
            bp_store = std::dynamic_pointer_cast<BackPackStore>(field);
            bp_store->set_size(size);
            bp_store->set_position(calculate_sprite_position(size, p));
            break;
        default:
            break;
        }
    }
    // skin = std::make_shared<Skin>("hero profile", );
}

std::map <BackPackTypeSystem, MenuTextureStore> BackPackMenu::load_textures(fs::path path_to_file) {
    std::map <BackPackTypeSystem, MenuTextureStore> T;
    std::cout << "#=#=#=#=# opening fstream with \"" << path_to_file << "\" file..." << std::endl;
    std::ifstream file(path_to_file);
    if (!file) {
        std::cout << "cannot find this file: " << path_to_file << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }

    std::string type;
    fs::path file_path;
    size_t number{};
    size_t x_in{}, y_in{};
    size_t width{}, height{};
    double n_repeat_x{}, n_repeat_y;
    while (file >> type) {
        if (type.substr(0, 2) == "//") {
            std::cout << type << "\n";
            continue;
        }
        file >> number;
        std::cout << "field type: " << type << "\n";
        if (true/*effect_types.find(types[type]) != effect_types.end()*/) {
            for (size_t i = 0; i < number; ++i) {
                file >> x_in >> y_in;
                file >> width >> height;
                file >> n_repeat_x >> n_repeat_y;
                //std::(file, file_path);
                file >> file_path;

                BackPackTypeSystem r_type = bp_menu_types[type];
                T[r_type].textures.push_back(std::make_shared<sf::Texture>());
                sf::Vector2 position_in((int) x_in, (int) y_in);
                sf::Vector2 size_f((float) (width * n_repeat_x), (float) (height * n_repeat_y));
                sf::Vector2 size_i((int) (width), (int) (height));
                sf::Vector2 size_r((int) (width * n_repeat_x), (int) (height * n_repeat_y));
                if (!T[r_type].textures[T[r_type].textures.size()-1]->loadFromFile(static_path / file_path, sf::IntRect(position_in, size_i))) {
                    std::cout << "cannot read texture from file : " << file_path << std::endl;
                    throw std::invalid_argument("there is not such file with texture");
                }
            }
        }
        else
            throw std::runtime_error(std::string("this is not effect in file: ") + std::string(file_path));
    }

    file.close();

    return T;
}