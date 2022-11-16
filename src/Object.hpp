#ifndef SFML_OBJ_CLASS
#define SFML_OBJ_CLASS

#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

#include <SFML/Graphics.hpp>

#include "Collider.hpp"
#include "constants.hpp"

struct ObjTextureStore {
    std::vector <std::shared_ptr<sf::Texture>> textures;
    std::shared_ptr<sf::Texture> current_texture;
    std::shared_ptr<sf::Texture> preview;
    std::shared_ptr<sf::Texture> bp_texture;
};
template <typename TypeSystem>
class Obj {
public:
    using pair_ui64_t = std::pair<uint64_t, uint64_t>;
protected:
    pair_ui64_t position = std::make_pair(0, 0);
public:
    pair_ui64_t w_position = std::make_pair(0, 0);
    // void set_position(const pair_ui64_t & p);
    pair_ui64_t get_position() const
    { return position; }


    Obj() = default;
    Obj(const pair_ui64_t & position, const sf::Sprite & sprite);
    Obj(std::string name, pair_ui64_t position);
    Obj(const Obj &) = default;
    virtual ~Obj() {}

    unsigned char get_layer();

    virtual TypeSystem get_type() const = 0;
    virtual void read(std::ifstream & ) = 0;
    void set_texture(fs::path file_path, pair_ui64_t p_in, pair_ui64_t scale, pair_ui64_t n_repeat);
    // void set_sprite_position(pair_ui64_t p);

protected:
    Collider collider;
    sf::Sprite sprite;
    ObjTextureStore textures;
    // std::shared_ptr<sf::Texture> texture = nullptr;
    unsigned char layer = 0;
    std::string name;
public:
    const sf::Sprite & get_sprite() const
    { return sprite; }
    sf::Sprite & get_sprite()
    { return sprite; }
    sf::Sprite get_sprite_copy() const
    { return sprite; }
    const std::shared_ptr<sf::Texture> & get_texture() const
    { return textures.current_texture; }
    const std::string & get_name() const
    { return name; }
    // void move(int x, int y);

    double get_velocity() const
    { return collider.velocity; }
    double get_v_angle() const
    { return collider.moving_angle; }
    bool is_mobile()
    { return collider.mobility; }
    void set_velocity(double v) 
    { collider.velocity = v; }
    void set_v_angle(double a)
    { collider.moving_angle = a; }

public:
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
        if (!textures.current_texture->loadFromFile(static_path / file_path, sf::IntRect(position_in, size_i))) {
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

    void move(int x, int y) {
        position.first += x;
        position.second += y;
    }

private:
    TypeSystem type;
};

#endif