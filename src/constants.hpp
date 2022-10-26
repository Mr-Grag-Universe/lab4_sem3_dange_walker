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


#include "World.hpp"
#include "Map.hpp"
#include "Object.hpp"

template <typename T>
double distance(const std::pair <T, T> & p1, const std::pair <T, T> & p2) {
    return std::sqrt(pow((double)p1.first-(double)p2.first, 2) + pow((double)p1.second-(double)p2.second, 2));
}

#endif