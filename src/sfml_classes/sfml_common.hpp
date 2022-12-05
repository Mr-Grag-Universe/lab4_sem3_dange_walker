#ifndef SFML_COMMON
#define SFML_COMMON

#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "../constants.hpp"

namespace fs = std::filesystem;
using pair_ui64_t = std::pair <u_int64_t, u_int64_t>;

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

struct ObjTextureStore {
    std::vector <std::shared_ptr<sf::Texture>> textures;
    std::shared_ptr<sf::Texture> current_texture;
    std::shared_ptr<sf::Texture> preview;
    std::shared_ptr<sf::Texture> bp_texture;

    sf::Clock standard_clock;
    sf::Time standard_period;
    sf::Time standard_life_time;

    std::vector<std::shared_ptr<sf::SoundBuffer>> sounds;

    bool is_static = true;
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

namespace my_sfml_colors {
    static sf::Color MyDarkSlateGray = sf::Color(47, 79, 79);
    static sf::Color MyGrey11 = sf::Color(28, 28, 28);
    static sf::Color MyDarkSlateBlue = sf::Color(72, 61, 139);
};

namespace msc = my_sfml_colors;

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