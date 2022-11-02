#ifndef OBJ_CLASS
#define OBJ_CLASS

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

enum ObjectType {
    WALL,
    FLOOR,
    DOOR,
    ALIVE,
    CHEST,
    BACKPACK,
    SWARD,

    CHARACTER,
    SLIME,

    WEAPON,

    MW_WAVE,
};

#ifndef MY_TYPES
#define MY_TYPES
inline std::map <std::string, enum ObjectType> types = {
    { "floor",      FLOOR     },
    { "door" ,      DOOR      },
    { "wall" ,      WALL      },
    { "chest",      CHEST     },
    { "sward",      SWARD     },
    { "backpack",   BACKPACK  },

    { "hero",       CHARACTER },
    { "slime",      SLIME     },


    { "weapon",     WEAPON    },

    { "mw_wave",    MW_WAVE   },
};
#endif

class Obj;
class Obj {
protected:
    std::pair<unsigned int, unsigned int> position = std::make_pair(0, 0);
public:
    std::pair<unsigned int, unsigned int> w_position = std::make_pair(0, 0);
    void set_position(const std::pair<unsigned int, unsigned int> & p);
    // const std::pair<unsigned int, unsigned int> & get_position() const {
    //     return position;
    // }
    std::pair<unsigned int, unsigned int> get_position() const
    { return position; }


    Obj() = default;
    Obj(const std::pair<unsigned int, unsigned int> & position, const sf::Sprite & sprite);
    Obj(std::string name, std::pair<unsigned int, unsigned int> position);
    Obj(const Obj &) = default;
    virtual ~Obj() {}

    unsigned char get_layer();

    virtual ObjectType get_type() = 0;
    virtual void read(std::ifstream & ) = 0;
    void set_texture(fs::path file_path, std::pair<unsigned int, unsigned int> p_in, std::pair<unsigned int, unsigned int> scale, std::pair<unsigned int, unsigned int> n_repeat);
    void set_sprite_position(std::pair<unsigned int, unsigned int> p);

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
    ObjectType type;
};

#endif