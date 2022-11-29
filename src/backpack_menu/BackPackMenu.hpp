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
#include "WeaponInArm.hpp"
#include "BackPackStore.hpp"
#include "CharBar.hpp"
#include "../alive_obj/Character.hpp"

class BackPackMenu {
protected:
    Container & container;
    std::vector <std::shared_ptr<BPMObj>> all_menu_fields;
    std::map <BackPackTypeSystem, MenuTextureStore> textures;

    std::shared_ptr<Skin> skin = std::make_shared<Skin>();
    std::shared_ptr<WeaponInArm> weapon = std::make_shared<WeaponInArm>();
    std::shared_ptr<BackPackStore> bp_store;
    std::shared_ptr<CharBar<Character>> char_bar; 
    // std::shared_ptr<>
public:
    const std::vector <std::shared_ptr<BPMObj>> & get_all_menu_fields() const 
    { return all_menu_fields; }
    BackPackMenu(Character & c);
    ~BackPackMenu() = default;

    std::map <BackPackTypeSystem, MenuTextureStore> load_textures(fs::path path);
};

#endif