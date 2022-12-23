#include "../constants.hpp"

#include "GameObject.hpp"
#include "Character.hpp"
#include "../weapon/Sward.hpp"

void Character::read(std::ifstream & file) {
    std::string src;
    unsigned int x_in{}, y_in{};
    unsigned int width{}, height{};
    try {
        file >> name;
        file >> src;
        file >> x_in >> y_in;
        file >> width >> height;
        size = std::make_pair(width, height);
    } catch (...) {
        std::cout << "cannot read data about char" << std::endl;
        throw std::runtime_error("file reading error");
    }

    this->set_position((pair_ui64_t) std::make_pair(800, 600));
    
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

std::shared_ptr<Effect> Character::use_weapon() {
    std::cout << "character used weapon" << std::endl;
    return weapon->use(*this);
}

void fill_backpack() {
    // backpack.read();
}

//=============== other methods ==============//

void Character::push_quest(std::shared_ptr<Quest> quest) {
    quests.push_back(quest);
}