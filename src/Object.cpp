#include <vector>
#include <iostream>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Object.hpp"

void Obj::set_texture(std::string src_file_name, std::pair<unsigned int, unsigned int> p_in, std::pair<unsigned int, unsigned int> scale, std::pair<unsigned int, unsigned int> n_repeat) {
    texture = std::make_unique<sf::Texture>();
    *texture = sf::Texture();
    if (n_repeat.first || n_repeat.second) {
        texture->setRepeated(true);
    }
    sf::Vector2 position_in((int) p_in.first, (int) p_in.second);
    sf::Vector2 size_f((float) (scale.first * n_repeat.first), (float) (scale.second * n_repeat.second));
    sf::Vector2 size_i((int) (scale.first), (int) (scale.second));
    sf::Vector2 size_r((int) (scale.first * n_repeat.first), (int) (scale.second * n_repeat.second));
    if (!texture->loadFromFile("/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/" + src_file_name, sf::IntRect(position_in, size_i))) {
        std::cout << "cannot read texture from file : " << src_file_name << std::endl;
        throw std::invalid_argument("there is not such file with texture");
    }

    sprite.setTexture(*texture);
    if (n_repeat.first || n_repeat.second) {
        sprite.setTextureRect(sf::IntRect(sf::Vector2(0, 0), size_r));
    }
}

void Obj::set_position(const std::pair<unsigned int, unsigned int> & p) {
    position = p;
    // sf::Vector2 p_v((float) p.first, (float) p.second);
}

void Obj::set_sprite_position(std::pair<unsigned int, unsigned int> p) {
    sf::Vector2 p_v((float) p.first, (float) p.second);
    sprite.setPosition(p_v);
}

void Obj::move(int x, int y) {
    position.first += x;
    position.second += y;
}