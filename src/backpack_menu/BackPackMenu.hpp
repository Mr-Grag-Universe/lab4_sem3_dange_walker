#ifndef BACK_PACK_MENU_CLASS
#define BACK_PACK_MENU_CLASS

#include <vector>
#include <map>
#include <algorithm>
#include <filesystem>
namespace fs = std::filesystem;

#include "BPMObject.hpp"
#include "../containers/BackPack.hpp"
#include "../constants.hpp"
#include "Skin.hpp"

class BackPackMenu {
protected:
    const Container & container;
    std::vector <std::shared_ptr<BPMObj>> all_menu_fields;
    std::map <BackPackTypeSystem, std::vector <sf::Texture>> textures;

    std::shared_ptr<Skin> skin;
    // std::shared_ptr<>
public:
    const std::vector <std::shared_ptr<BPMObj>> & get_all_menu_fields() const 
    { return all_menu_fields; }
    BackPackMenu(const Container & c);
    ~BackPackMenu() = default;

    std::map <BackPackTypeSystem, MenuTextureStore> load_textures(fs::path path);
};

#endif