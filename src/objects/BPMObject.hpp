#ifndef BPMOBJECT_CLASS
#define BPMOBJECT_CLASS

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "../containers/BackPack.hpp"
#include "../constants.hpp"
#include "../alive_obj/Alive.hpp"

class BPMObj : public Obj<BackPackTypeSystem> {
protected:
    char layer = 0;
    pair_ui64_t w_position = std::make_pair(0, 0);
    sf::Sprite sprite;
    ObjTextureStore textures;
public:
    BPMObj() {}
    BPMObj(std::string n, pair_ui64_t p) {
        position = p;
        name = n;
    }
    BPMObj(const Obj & o) {
        position = o.get_position();
        layer = o.get_layer();
        name = o.get_name();
        size = o.get_size();
    }
    virtual void draw(sf::RenderWindow & window) const = 0;
    virtual void edit(const Alive &) = 0;

    const sf::Sprite & get_sprite() const
    { return sprite; }
    sf::Sprite & get_sprite()
    { return sprite; }
    sf::Sprite get_sprite_copy() const
    { return sprite; }
    const std::shared_ptr<sf::Texture> & get_texture() const
    { return textures.current_texture; }

    void set_texture(fs::path file_path, std::pair<unsigned int, unsigned int> p_in, std::pair<unsigned int, unsigned int> scale, std::pair<unsigned int, unsigned int> n_repeat) {
        textures.current_texture = std::make_unique<sf::Texture>();
        *textures.current_texture = sf::Texture();
        if (n_repeat.first || n_repeat.second) {
            textures.current_texture->setRepeated(true);
        }
        sf::Vector2 position_in((int) p_in.first, (int) p_in.second);
        sf::Vector2 size_f((float) (scale.first * n_repeat.first), (float) (scale.second * n_repeat.second));
        sf::Vector2 size_i((int) (scale.first), (int) (scale.second));
        sf::Vector2 size_r((int) (scale.first * n_repeat.first), (int) (scale.second * n_repeat.second));
        if (!textures.current_texture->loadFromFile(mp::img / file_path, sf::IntRect(position_in, size_i))) {
            std::cout << "cannot read texture from file : " << file_path << std::endl;
            throw std::invalid_argument("there is not such file with texture");
        }

        sprite.setTexture(*textures.current_texture);
        if (n_repeat.first || n_repeat.second) {
            sprite.setTextureRect(sf::IntRect(sf::Vector2(0, 0), size_r));
        }
    }
    void set_texture(std::shared_ptr<sf::Texture> t, pair_ui64_t size) {
        textures.current_texture = t;
        sprite.setTexture(*t);
        sprite.scale(sf::Vector2f((double)size.first/(double)t->getSize().x, (double)size.second/(double)t->getSize().y));
    }

    void set_position(const pair_ui64_t & p) {
        position = p;
        // sf::Vector2 p_v((float) p.first, (float) p.second);
    }

    void set_sprite_position(pair_ui64_t p) {
        sf::Vector2 p_v((float) p.first, (float) p.second);
        sprite.setPosition(p_v);
    }
};

#endif