#ifndef OBJ_CLASS
#define OBJ_CLASS

#include <algorithm>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Collider.hpp"
#include "constants.hpp"

class Obj {
public:
    Obj() = default;
    Obj(const std::pair<unsigned int, unsigned int> & position, const sf::Sprite & sprite);
    Obj(const Obj &);
    ~Obj() = default;

    // methods

    /// @return current position of an object 
    std::pair<unsigned int, unsigned int> get_position();
    /// @return on which layer current object is staying
    unsigned char get_layer();

    virtual void f() = 0;
protected:
    Collider collider;
    sf::Sprite sprite;
    std::pair<unsigned int, unsigned int> position = std::make_pair(HEIGHT/2, WIDTH/2);
    unsigned char layer = 0;
private:
};

#endif