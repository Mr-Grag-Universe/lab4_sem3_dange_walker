#include <vector>
#include <iostream>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "constants.hpp"
#include "Object.hpp"

void Obj::set_texture(fs::path file_path, std::pair<unsigned int, unsigned int> p_in, std::pair<unsigned int, unsigned int> scale, std::pair<unsigned int, unsigned int> n_repeat) {
    texture = std::make_unique<sf::Texture>();
    *texture = sf::Texture();
    if (n_repeat.first || n_repeat.second) {
        texture->setRepeated(true);
    }
    sf::Vector2 position_in((int) p_in.first, (int) p_in.second);
    sf::Vector2 size_f((float) (scale.first * n_repeat.first), (float) (scale.second * n_repeat.second));
    sf::Vector2 size_i((int) (scale.first), (int) (scale.second));
    sf::Vector2 size_r((int) (scale.first * n_repeat.first), (int) (scale.second * n_repeat.second));
    if (!texture->loadFromFile(static_path / file_path, sf::IntRect(position_in, size_i))) {
        std::cout << "cannot read texture from file : " << file_path << std::endl;
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