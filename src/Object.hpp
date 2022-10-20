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
    /// @brief устанавливает глобальную координату объекта и для его спрайта (в World)
    /// @param p 
    void set_position(const std::pair<unsigned int, unsigned int> & p);
    // const std::pair<unsigned int, unsigned int> & get_position() const {
    //     return position;
    // }
    /// @return current position of an object 
    std::pair<unsigned int, unsigned int> get_position() const {
        return position;
    }
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

    /// @return on which layer current object is staying
    unsigned char get_layer();

    virtual ObjectType get_type() = 0;
    void set_texture(std::string , std::pair<unsigned int, unsigned int> p, std::pair<unsigned int, unsigned int> p_in, std::pair<unsigned int, unsigned int> scale);
    // virtual void f() = 0;

protected:
    Collider collider;
    sf::Sprite sprite;
    std::unique_ptr<sf::Texture> texture = nullptr;
    unsigned char layer = 0;
    std::string name;
public:
    const sf::Sprite & get_sprite() const { return sprite; }
    sf::Sprite & get_sprite() { return sprite; }
    sf::Sprite get_sprite_copy() {
        sf::Sprite res = sprite;
        sf::Texture t = *texture;
        
        return sprite;
    }
    const std::unique_ptr<sf::Texture> & get_texture() const { return texture; }
    const std::string & get_name() const { return name; }
private:
    ObjectType type;
};

#endif