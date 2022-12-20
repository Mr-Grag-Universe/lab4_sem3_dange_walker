#include "GameObject.hpp"
#include "Skeleton.hpp"
#include "World.hpp"

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

void Skeleton::iterate(World & w) {
    pair_ui64_t p_h = w.get_hero().get_position();
    double d = distance(position, p_h);
    if (d < visibility_radius) {
        if (d < 1) {
            collider.velocity = 0;
            return;
        }
        collider.velocity = 3;
        pair_ui64_t p_o = position;
        double d_x = (long long)p_h.first - (long long)p_o.first;
        double d_y = (long long)p_h.second - (long long)p_o.second;
        double a{};
        a = (d_x == 0) ? (d_y > 0) ? M_PI/2 : -M_PI/2 : atan(d_y / d_x);
        if (d_x < 0)
            a += M_PI;
        collider.moving_angle = a;
    }
    else {
        collider.velocity = 0;
    }
}

void Skeleton::dialog(World & w) {

}