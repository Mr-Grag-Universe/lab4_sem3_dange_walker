#ifndef GAME_OBJ_CLASS
#define GAME_OBJ_CLASS

#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

#include "Object.hpp"


class GameObj : public Obj<GameTypeSystem> {

};

#endif