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
    enum ObjectType {
        WALL,
        FLOOR,
        DOOR,
        ALIVE,
        CHARACTER,
    };

    Obj() = default;
    Obj(const std::pair<unsigned int, unsigned int> & position, const sf::Sprite & sprite);
    Obj(const Obj &);
    virtual ~Obj() {
        
    }

    // methods

    /// @return current position of an object 
    std::pair<unsigned int, unsigned int> get_position() const {
        return position;
    }
    /// @return on which layer current object is staying
    unsigned char get_layer();

    virtual ObjectType get_type() = 0;
    void set_texture(std::string , std::pair<unsigned int, unsigned int> p, std::pair<unsigned int, unsigned int> p_in, std::pair<unsigned int, unsigned int> scale);
    // virtual void f() = 0;

    void set_position(const std::pair<unsigned int, unsigned int> & p);
protected:

    Collider collider;
    sf::Sprite sprite;
    unsigned char layer = 0;
    std::string name;
public:
    const sf::Sprite & get_sprite() const {
        return sprite;
    }
    const std::string & get_name() const {
        return name;
    }
private:
    ObjectType type;
};

#endif