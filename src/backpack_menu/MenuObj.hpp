#ifndef MENU_OBJ_CLASS
#define MENU_OBJ_CLASS
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

#include <SFML/Graphics.hpp>

#include "../physics/Collider.hpp"

enum MenuObjectType {
    SKIN,
    WEAPON_IN_ARMS,
};

#ifndef MY_MENU_TYPES
#define MY_MENU_TYPES
inline std::map <std::string, enum MenuObjectType> menu_types = {
    { "skin",      SKIN     },
    { "weapon",    WEAPON_IN_ARMS   },
};
#endif

class MenuObj;
class MenuObj {
    using pair_ui64_t = std::pair<uint64_t, uint64_t>;
protected:
    std::pair<uint64_t, uint64_t> position = std::make_pair(0, 0);
public:
    pair_ui64_t w_position = std::make_pair(0, 0);
    void set_position(const pair_ui64_t & p);
    pair_ui64_t get_position() const
    { return position; }


    MenuObj() = default;
    MenuObj(const pair_ui64_t & position, const sf::Sprite & sprite);
    MenuObj(std::string name, pair_ui64_t position);
    MenuObj(const MenuObj &) = default;
    virtual ~MenuObj() {}

    unsigned char get_layer();

    virtual MenuObjectType get_type() = 0;
    virtual void read(std::ifstream & ) = 0;
    void set_texture(fs::path file_path, pair_ui64_t p_in, pair_ui64_t scale, pair_ui64_t n_repeat);
    void set_sprite_position(pair_ui64_t p);

protected:
    Collider collider;
    sf::Sprite sprite;
    std::shared_ptr<sf::Texture> texture = nullptr;
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
    { return texture; }
    const std::string & get_name() const
    { return name; }
    void move(int x, int y);

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
private:
    MenuObjectType type;
};

#endif