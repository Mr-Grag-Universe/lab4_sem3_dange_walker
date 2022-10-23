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

std::shared_ptr<Obj> Door::read(std::ifstream & file) {
    std::shared_ptr<Obj> res = std::make_shared<Door>();
    return res;
}