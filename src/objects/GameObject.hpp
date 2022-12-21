#ifndef GAME_OBJ_CLASS
#define GAME_OBJ_CLASS

#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <filesystem>
#include <queue>
#include <chrono>
namespace fs = std::filesystem;

#include "Object.hpp"
#include "../constants.hpp"

/// @brief класс игровых объектов с соответствующими элементами логики
/// пример с логикой времени от Андрея Ивановича взят отсюда.
/// но я выкрутился через chrono. делать больше было лень
class GameObj : public Obj<GameTypeSystem> {
public:
    using pair_ui64_t = std::pair<uint64_t, uint64_t>;
protected:
    // pair_ui64_t position = std::make_pair(0, 0);
    char layer = 0;
    using chrono_time_point = std::chrono::time_point<std::chrono::steady_clock>;
    chrono_time_point life_time;
    chrono_time_point born = std::chrono::steady_clock::now();
    chrono_time_point period;
    uint64_t phase = 0;
    uint64_t number_of_phases = 0;
public:
    chrono_time_point get_born()
    { return born; }
    pair_ui64_t get_position() const
    { return position; }
    // void set_position(pair_ui64_t p)
    // { position = p; }

    chrono_time_point get_time() const
    { return period; }
    void set_time(chrono_time_point p)
    { period = p; }
    uint64_t get_phase() const
    { return phase; }
    void set_phase(uint64_t p)
    { phase = p; }
    void next_phase()
    { phase = (phase+1)%number_of_phases; }
    uint64_t get_number_of_phases() const
    { return number_of_phases; }
    void set_number_of_phases(uint64_t n)
    { number_of_phases = n; }

    GameObj() = default;
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
    virtual const std::string & get_name() const
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

protected:
    std::queue<size_t> sounds_queue{};
public:
    std::queue<size_t> & get_sounds_queue()
    { return sounds_queue; }

    const std::queue<size_t> & get_sounds_queue() const
    { return sounds_queue; }

    std::queue<size_t> extract_sound_queue()
    { return std::move(sounds_queue); }
    
    void push_sound(size_t i)
    { sounds_queue.push(i); }
};

#endif