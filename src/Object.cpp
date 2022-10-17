#include <vector>
#include <iostream>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Object.hpp"

void Obj::set_texture(std::string src_file_name, std::pair<unsigned int, unsigned int> p, std::pair<unsigned int, unsigned int> p_in, std::pair<unsigned int, unsigned int> scale) {
    sf::Texture * texture = new sf::Texture;
    *texture = sf::Texture();
    sf::Vector2 position((float) p.first, (float) p.second);
    sf::Vector2 position_in((int) p_in.first, (int) p_in.second);
    sf::Vector2 size_f((float) scale.first, (float) scale.second);
    sf::Vector2 size_i((int) scale.first, (int) scale.second);
    if (!texture->loadFromFile("/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/" + src_file_name, sf::IntRect(position_in, size_i))) {
        std::cout << "cannot read texture from file : " << src_file_name << std::endl;
        throw std::invalid_argument("there is not such file with texture");
    }

    sprite.setPosition(position);
    sprite.setScale(size_f);
    // sprite.setColor(sf::Color::Green);
    sprite.setTexture(*texture);
    // sprite.setTextureRect();
    std::cout << "scale_init: " << scale.first << scale.second << "\nscale: " << sprite.getScale().x << sprite.getScale().y << ";\n";
    
    // sprite.setTexture(texture);
}

void Obj::set_position(const std::pair<unsigned int, unsigned int> & p) {
    position = p;
}