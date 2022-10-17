#ifndef CONSTS
#define CONSTS

#define WIDTH 600
#define HEIGHT 400

#include <algorithm>
#include <cmath>

template <typename T>
double distance(const std::pair <T, T> & p1, const std::pair <T, T> & p2) {
    return std::sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
}

#endif