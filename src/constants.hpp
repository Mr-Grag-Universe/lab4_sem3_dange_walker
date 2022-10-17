#ifndef CONSTS
#define CONSTS

#define WIDTH 600
#define HEIGHT 800

//#define SCRINE_WIDTH 1080

#include <algorithm>
#include <cmath>

template <typename T>
double distance(const std::pair <T, T> & p1, const std::pair <T, T> & p2) {
    std::cout << "positions: (" << p1.first << "; " << p1.second << "), (" << p2.first  << "; " << p2.second << ")\n";
    std::cout << "distance: " << std::sqrt(pow((double)p1.first-(double)p2.first, 2) + pow((double)p1.second-(double)p2.second, 2)) << "\n";
    return std::sqrt(pow((double)p1.first-(double)p2.first, 2) + pow((double)p1.second-(double)p2.second, 2));
}

#endif