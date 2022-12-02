#include "GameObject.hpp"
#include "Slime.hpp"

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