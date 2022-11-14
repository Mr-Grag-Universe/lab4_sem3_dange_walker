#ifndef CONSTS
#define CONSTS

#define WIDTH 600
#define HEIGHT 800

//#define SCRINE_WIDTH 1080

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

template <typename T>
double distance(const std::pair <T, T> & p1, const std::pair <T, T> & p2) {
    return std::sqrt(pow((double)p1.first-(double)p2.first, 2) + pow((double)p1.second-(double)p2.second, 2));
}


#define STATIC_FILES_SRC_PATH "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/static/"

static fs::path static_path(fs::canonical(STATIC_FILES_SRC_PATH));
static fs::path first_room("first_room.txt");
static fs::path containers("containers.txt");
static fs::path npc_file("npc.txt");
static fs::path hero_file("hero.txt");
static fs::path effect_file("effects_src.txt");

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

enum MyRGBColors {
    DarkSlateGray,
    DarkSlateBlue,
};

static std::map <MyRGBColors, std::tuple<uint8_t, uint8_t, uint8_t>> color_collection = {
    { DarkSlateGray, std::make_tuple(47, 79, 79) },
    { DarkSlateBlue, std::make_tuple(72, 61, 139) },
};

// static std::pair <size_t, size_t> calculate_sprite_position(const sf::Texture & t, std::pair<size_t, size_t> p) {
//     return std::make_pair((p.first-t.getSize().x)/2, (p.second-t.getSize().y)/2);
//}

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
    } BPMenuType;


};

#endif