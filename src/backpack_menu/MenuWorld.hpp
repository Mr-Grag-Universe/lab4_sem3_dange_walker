#ifndef MENU_WORLD_CLASS
#define MENU_WORLD_CLASS

#include "../World.hpp"
#include "MenuObj.hpp"

class MenuWorld : public World {
private:
    std::vector <std::shared_ptr<MenuObj>> all_things;
    mode = BACKPACK_MENU;

    static std::vector <std::shared_ptr<MenuObj>> load_things_from_file(const std::string & file_name);
};

#endif