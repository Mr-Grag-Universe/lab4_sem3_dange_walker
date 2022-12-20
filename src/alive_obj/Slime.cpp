#include "GameObject.hpp"
#include "Slime.hpp"
#include "World.hpp"

void Slime::read(std::ifstream & file) {
    unsigned int x{}, y{};
    unsigned int x_in{}, y_in{};
    unsigned int width{}, height{};

    file >> x >> y;
    file >> x_in >> y_in;
    file >> width >> height;
    size = std::make_pair(width, height);

    // std::pair <unsigned int, unsigned int> p_in = std::make_pair(x_in, y_in);
    // std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);

    // std::shared_ptr<Obj> res = std::make_shared<Wall>();
    // this->set_texture(source_file_name, p_in, scale, std::make_pair(x_rep, y_rep));
    // this->set_size(std::make_pair(100, 100));
    position = std::make_pair(x, y);
}

void Slime::iterate(World & w) {
    Character & hero = w.get_hero();
    pair_ui64_t p_h = hero.get_position();
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

    if (d < 10) {
        std::cout << "make damage\n";
        hero.damage(damage);
        std::cout << "hero health: " << hero.get_helth() << std::endl;
    }
}

void Slime::dialog(World & w) {

}