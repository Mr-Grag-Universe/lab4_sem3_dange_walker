#include <SFML/Graphics.hpp>

#include "../weapon/Sward.hpp"
#include "../constants.hpp"

#include "../Object.hpp"
#include "../world.hpp"
#include "Character.hpp"

void Character::read(std::ifstream & file) {
    std::string src;
    unsigned int x_in{}, y_in{};
    unsigned int width{}, height{};
    try {
        file >> name;
        file >> src;
        file >> x_in >> y_in;
        file >> width >> height;
    } catch (...) {
        std::cout << "cannot read data about char" << std::endl;
        throw std::runtime_error("file reading error");
    }

    this->set_position((pair_ui64_t) std::make_pair(WIDTH, HEIGHT));
    std::pair <unsigned int, unsigned int> position_in = std::make_pair(x_in, y_in);
    std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);
    
    this->set_texture(src, position_in, scale, std::make_pair(1, 1));
    // this->set_sprite_position(std::make_pair(WIDTH, HEIGHT));
    
    std::string type;
    while (file >> type) {
        switch (types[type]) {
        case BACKPACK:
            backpack = BackPack();
            backpack.read(file);
            break;
        case WEAPON: {
            file >> type;
            switch (types[type]) {
            case SWARD: {
                weapon = std::make_shared<Sward>();
                weapon->read(file);
                if (!weapon->is_it_using())
                    weapon->switch_usage();
                backpack.push(weapon);
                break;
            }
            
            default:
                std::cout << "unknown type of object in backpack";
                break;
            }
            break;
        }

        default:
            break;
        }
    }
}

void Character::draw(sf::RenderWindow & window) {
    window.draw(sprite);
}

void Character::draw_backpack_menu(sf::RenderWindow & window) {
    
}

std::shared_ptr<Effect> Character::use_weapon() {
    std::cout << "character used weapon" << std::endl;
    return weapon->use(world, *this);
}

void fill_backpack() {
    // backpack.read();
}