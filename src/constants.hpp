#ifndef CONSTS
#define CONSTS

#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

using pair_ui64_t = std::pair <u_int64_t, u_int64_t>;


enum GameTypeSystem {
    WALL,
    FLOOR,
    DOOR,
    ALIVE,
    CHEST,
    BACKPACK,
    SWARD,

    CHARACTER,
    SLIME,
    SKELETON,

    WEAPON,

    MW_WAVE,
};
enum BackPackTypeSystem {
    SKIN,
    WEAPON_IN_ARMS,
    BACK_PACK_STORE,
    CELL,
    CHAR_BAR,
    STATUS_BAR,
    LABEL,
};

#ifndef MY_TYPES
#define MY_TYPES
static std::map <std::string, enum GameTypeSystem> types = {
    { "floor",      FLOOR     },
    { "door" ,      DOOR      },
    { "wall" ,      WALL      },
    { "chest",      CHEST     },
    { "sward",      SWARD     },
    { "backpack",   BACKPACK  },

    { "hero",       CHARACTER },
    { "slime",      SLIME     },
    { "skeleton",   SKELETON  },


    { "weapon",     WEAPON    },

    { "mw_wave",    MW_WAVE   },
};
static std::map <std::string, BackPackTypeSystem> bp_menu_types = {
    { "skin",        SKIN      },
    { "weapon", WEAPON_IN_ARMS },
    { "bp_store", BACK_PACK_STORE },
    { "cell",       CELL },
    { "char_bar",   CHAR_BAR },
    { "status_bar", STATUS_BAR },
    { "label",      LABEL },
};
#endif

static std::vector <GameTypeSystem> interractive_objs = {
    CHEST,
    SLIME,
    SWARD,
};
static std::vector <GameTypeSystem> i_containers = {
    CHEST,
};

template <typename T, typename U>
double distance(const std::pair <T, T> & p1, const std::pair <U, U> & p2) {
    return std::sqrt(pow((double)p1.first-(double)p2.first, 2) + pow((double)p1.second-(double)p2.second, 2));
}

namespace my_pathes {

    #define STATIC_FILES_SRC_PATH "/home/stepan/Desktop/vs_code_game/src/static/"

    static fs::path static_path(fs::canonical(STATIC_FILES_SRC_PATH));
    static fs::path font = static_path / fs::path("font");
    static fs::path img = static_path / fs::path("img");
    static fs::path logs = static_path / fs::path("logs");
    static fs::path sound = static_path / fs::path("sound");

    static fs::path first_room("first_room.txt");
    static fs::path containers("containers.txt");
    static fs::path npc_file("npc.txt");
    static fs::path hero_file("hero.txt");
    static fs::path effect_file("effects_src.txt");
    static fs::path game_obj_file("game_obj_src.txt");

}
namespace mp = my_pathes;

[[maybe_unused]] static bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

enum MyRGBColors {
    DarkSlateGray,
    DarkSlateBlue,
};

static std::map <MyRGBColors, std::tuple<uint8_t, uint8_t, uint8_t>> color_collection = {
    { DarkSlateGray, std::make_tuple(47, 79, 79) },
    { DarkSlateBlue, std::make_tuple(72, 61, 139) },
};

inline pair_ui64_t calculate_sprite_position(pair_ui64_t size, pair_ui64_t p) {
    return std::make_pair((u_int64_t) (p.first-size.first/2), (u_int64_t) (p.second-size.second/2));
}

enum EffectType {
    MW_Wawe_effect,
};

#endif