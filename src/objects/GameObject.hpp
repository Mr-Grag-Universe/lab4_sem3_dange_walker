#ifndef GAME_OBJ_CLASS
#define GAME_OBJ_CLASS

#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

#include "Object.hpp"
#include "../constants.hpp"


class GameObj : public Obj<GameTypeSystem> {
public:
    using pair_ui64_t = std::pair<uint64_t, uint64_t>;
protected:
    pair_ui64_t position = std::make_pair(0, 0);
    char layer = 0;
public:
    pair_ui64_t get_position() const
    { return position; }
    void set_position(pair_ui64_t p)
    { position = p; }


    GameObj() = default;
    GameObj(const pair_ui64_t & position, const sf::Sprite & sprite);
    GameObj(std::string name, pair_ui64_t position);
    GameObj(const GameObj &) = default;
    virtual ~GameObj() {}

    virtual GameTypeSystem get_type() const = 0;
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
    GameTypeSystem type;
};

#endif