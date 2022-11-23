#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Slime.hpp"

void Slime::read(std::ifstream & file) {
    unsigned int x{}, y{};
    unsigned int x_in{}, y_in{};
    unsigned int width{}, height{};
    unsigned int x_rep{}, y_rep{};
    std::string source_file_name;

    file >> x >> y;
    file >> x_in >> y_in;
    file >> width >> height;
    file >> source_file_name;
    file >> x_rep >> y_rep;

    // std::pair <unsigned int, unsigned int> p_in = std::make_pair(x_in, y_in);
    // std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);

    // std::shared_ptr<Obj> res = std::make_shared<Wall>();
    // this->set_texture(source_file_name, p_in, scale, std::make_pair(x_rep, y_rep));
    position = std::make_pair(x, y);

    double h{};
    size_t v_r{};
    file >> h >> v_r;
}

// void Slime::draw(sf::RenderWindow & window) {
//     // window.draw(sprite);
// }