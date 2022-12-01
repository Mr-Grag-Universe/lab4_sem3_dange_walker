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

#include <SFML/System.hpp>

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

static bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
struct TextureStore {
    std::vector <std::shared_ptr<sf::Texture>> textures;
    std::pair <double, double> scale;
    sf::Time period;
    sf::Time life_time;
};
struct MenuTextureStore {
    std::vector <std::shared_ptr<sf::Texture>> textures;
};

/// @brief convert string like ..._xxx_xxx_xxx_._xxx_xxx_... to time in sfml format
/// @param s 
/// @return  time in sfml format
[[maybe_unused]] static sf::Time stotime(std::string s) {
    if (s.empty())
        throw std::invalid_argument("cannot convert empty string");

    std::vector <std::string> parts;
    std::stringstream  data(s);

    std::string line;
    while(std::getline(data,line,'_'))
        parts.push_back(line);

    double time_d = 0;
    bool flag = false;
    int digits = 0;
    for (auto p: parts) {
        if (p == ".") {
            flag = true;
            continue;
        } else if (!is_number(p))
            continue;
        
        if (flag) {
            digits += (int) p.size();
            time_d += std::stof(p) / pow(10, digits);
        } else {
            time_d = time_d * 10*p.size() + std::stof(p);
        }
    }

    if (parts.back() == "ms") {
        return sf::Time(sf::milliseconds(time_d));
    } else {
        throw std::invalid_argument("we don't know this unit of time measurement");
    }
}

static sf::Color MyDarkSlateGray = sf::Color(47, 79, 79);
static sf::Color MyGrey11 = sf::Color(28, 28, 28);
static sf::Color MyDarkSlateBlue = sf::Color(72, 61, 139);

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

class MyObjectTypes {
    [[maybe_unused]] enum GameObjectType {
        WALL,
        FLOOR,
        DOOR,
        ALIVE,
        CHEST,
        BACKPACK,
        SWARD,

        CHARACTER,
        SLIME,

        WEAPON,

        MW_WAVE,
    } GameType;

    [[maybe_unused]] enum BPMenuObjectType {
        SKIN,
        WEAPON_IN_ARMS,
        BACK_PACK_STORE,
    } BPMenuType;
};

enum EffectType {
    MW_Wawe_effect,
};

inline sf::Vector2f middle_rect_pos(const sf::RectangleShape & r, const sf::Vector2f & size) {
    sf::Vector2f res;
    sf::Vector2f r_pos = r.getPosition();
    sf::Vector2f r_size = r.getSize();
    res.x = r_pos.x + (r_size.x - size.x)/2;
    res.y = r_pos.y + (r_size.y - size.y)/2;

    return res;
}

namespace DrawFunctions {
    inline void drawGrid(sf::RenderWindow& win, int rows, int cols, const sf::FloatRect & f_rect){
        sf::Vector2f r_pos = f_rect.getPosition();
        sf::Vector2f r_size = f_rect.getSize();
        // initialize values
        int numLines = rows+cols+2;
        sf::VertexArray grid(sf::Lines, 2*(numLines));
        // win.setView(win.getDefaultView());
        float rowH = r_size.y/rows;
        float colW = r_size.x/cols;
        // row separators
        for(int i=0; i < rows+1; ++i) {
            int r = i;
            float rowY = rowH*r + r_pos.y;
            grid[i*2].position = {r_pos.x, rowY};
            grid[i*2+1].position = {r_pos.x+r_size.x, rowY};
        }
        // column separators
        for(int i=rows+1; i < numLines; ++i) {
            int c = i-(rows+1);
            float colX = colW*c + r_pos.x;
            grid[i*2].position = {colX, r_pos.y};
            grid[i*2+1].position = {colX, r_pos.y+r_size.y};
        }
        // draw it
        win.draw(grid);
    }
};

#endif