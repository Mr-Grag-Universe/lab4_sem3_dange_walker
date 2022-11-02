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

#endif