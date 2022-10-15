#ifndef OBJ_CLASS
#define OBJ_CLASS

#include <algorithm>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Collider.hpp"
#include "constants.hpp"

class Obj {
protected:
public:
    enum ObjectType {
        WALL,
        FLOOR,
        DOOR,
    };

    Obj() = default;
    Obj(const std::pair<unsigned int, unsigned int> & position, const sf::Sprite & sprite);
    Obj(const Obj &);
    virtual ~Obj() {
        
    }

    // methods

    /// @return current position of an object 
    std::pair<unsigned int, unsigned int> get_position();
    /// @return on which layer current object is staying
    unsigned char get_layer();

    virtual ObjectType get_type() = 0;
    void set_texture(std::string , std::pair<unsigned int, unsigned int> scale, std::pair<unsigned int, unsigned int> p);
    // virtual void f() = 0;
protected:

    Collider collider;
    sf::Sprite sprite;
    std::pair<unsigned int, unsigned int> position = std::make_pair(HEIGHT/2, WIDTH/2);
    unsigned char layer = 0;
    std::string name;
private:
    ObjectType type;
};

#endif