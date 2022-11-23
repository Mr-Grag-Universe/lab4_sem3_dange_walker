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
#include <SFML/Window.hpp>

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
    pair_ui64_t size = std::make_pair(0, 0);
    pair_ui64_t position = std::make_pair(0, 0);
    char layer = 0;
public:
    pair_ui64_t get_position() const
    { return position; }
    pair_ui64_t get_size() const
    { return size; }
    void set_position(pair_ui64_t p)
    { position = p; }


    Obj() = default;
    Obj(const pair_ui64_t & position, const sf::Sprite & sprite);
    Obj(std::string name, pair_ui64_t position);
    Obj(const Obj &) = default;
    virtual ~Obj() {}

    unsigned char get_layer();

    virtual TypeSystem get_type() const = 0;
    virtual void read(std::ifstream & ) = 0;
    // void set_texture(fs::path file_path, pair_ui64_t p_in, pair_ui64_t scale, pair_ui64_t n_repeat);
    // void set_sprite_position(pair_ui64_t p);

protected:
    Collider collider;
    std::string name;
public:
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
    char get_layer() const
    { return layer; }

    void move(int x, int y) {
        position.first += x;
        position.second += y;
    }

private:
    TypeSystem type;
};

#endif