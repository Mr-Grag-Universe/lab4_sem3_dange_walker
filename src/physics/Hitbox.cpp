#include <iostream>
#include <algorithm>
#include <vector>

#include "Hitbox.hpp"

std::vector <std::vector <bool>> & Hitbox::get_matrix() {
    return this->matrix;
}