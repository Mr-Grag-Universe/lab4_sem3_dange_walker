#include <vector>
#include <iostream>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Door.hpp"

/*
void Door::set_texture(std::string src_file_name, std::pair<unsigned int, unsigned int> scale, std::pair<unsigned int, unsigned int> p) {
    sf::Texture texture;
    if (!texture.loadFromFile("/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/" + src_file_name)) {
        std::cout << "cannot read texture from file : " << src_file_name << std::endl;
        throw std::invalid_argument("there is not such file with texture");
    }

    sprite.setTexture(texture);
    sf::Vector2 position((int) p.first, (int) p.second);
    sf::Vector2 size((int) scale.first, (int) scale.second);
    sprite.setTextureRect(sf::IntRect(position, size));
}
*/

void Door::read(std::ifstream & file) {
    unsigned int x{}, y{};
    unsigned int x_in{}, y_in{};
    unsigned int width{}, height{};
    unsigned int number{};
    std::string source_file_name;

    file >> x >> y;
    file >> x_in >> y_in;
    file >> width >> height;
    file >> source_file_name;
    file >> number;

    std::pair <unsigned int, unsigned int> p_in = std::make_pair(x_in, y_in);
    std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);

    //std::shared_ptr<Obj> res = std::make_shared<Door>();
    this->set_texture(source_file_name, p_in, scale);
    position = std::make_pair(x, y);

    // return res;
}