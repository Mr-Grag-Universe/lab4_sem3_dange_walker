#include "GameObject.hpp"
#include "Skeleton.hpp"

void Skeleton::read(std::ifstream & file) {
    unsigned int x{}, y{};
    unsigned int x_in{}, y_in{};
    unsigned int width{}, height{};

    file >> x >> y;
    file >> x_in >> y_in;
    file >> width >> height;
    size = std::make_pair(width, height);
    position = std::make_pair(x, y);
}