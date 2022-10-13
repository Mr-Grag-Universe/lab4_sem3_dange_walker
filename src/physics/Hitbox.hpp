#ifndef HITBOX_CLASS
#define HITBOX_CLASS

#include <vector>


/// @brief contain bool-array that describe form of an object
class Hitbox {
private:
    std::vector <std::vector <bool>> matrix;
public:
    Hitbox(/* args */);
    ~Hitbox();

    std::vector <std::vector <bool>> & get_matrix();
};

Hitbox::Hitbox(/* args */) {
}

Hitbox::~Hitbox() {
}


#endif