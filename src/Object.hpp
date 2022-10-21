#ifndef OBJ_CLASS
#define OBJ_CLASS

#include <algorithm>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Collider.hpp"
#include "constants.hpp"

class Obj {
protected:
    std::pair<unsigned int, unsigned int> position = std::make_pair(HEIGHT/2, WIDTH/2);
public:
    std::pair<unsigned int, unsigned int> w_position = std::make_pair(0, 0);
    void set_position(const std::pair<unsigned int, unsigned int> & p);
    // const std::pair<unsigned int, unsigned int> & get_position() const {
    //     return position;
    // }
    std::pair<unsigned int, unsigned int> get_position() const
    { return position; }

    enum ObjectType {
        WALL,
        FLOOR,
        DOOR,
        ALIVE,
        CHEST,
        CHARACTER,
        SWARD,
    };

    Obj() = default;
    Obj(const std::pair<unsigned int, unsigned int> & position, const sf::Sprite & sprite);
    Obj(std::string name, std::pair<unsigned int, unsigned int> position);
    Obj(const Obj &);
    virtual ~Obj() {}

    unsigned char get_layer();

    virtual ObjectType get_type() = 0;
    void set_texture(std::string, std::pair<unsigned int, unsigned int> p_in, std::pair<unsigned int, unsigned int> scale);
    void set_sprite_position(std::pair<unsigned int, unsigned int> p);

protected:
    Collider collider;
    sf::Sprite sprite;
    std::unique_ptr<sf::Texture> texture = nullptr;
    unsigned char layer = 0;
    std::string name;
public:
    const sf::Sprite & get_sprite() const
    { return sprite; }
    sf::Sprite & get_sprite()
    { return sprite; }
    sf::Sprite get_sprite_copy() const
    { return sprite; }
    const std::unique_ptr<sf::Texture> & get_texture() const
    { return texture; }
    const std::string & get_name() const
    { return name; }
    void move(int x, int y);
private:
    ObjectType type;
};

#endif