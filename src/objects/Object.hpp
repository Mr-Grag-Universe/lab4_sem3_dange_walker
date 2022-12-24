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

#include "Collider.hpp"
#include "constants.hpp"

/// @brief корневой класс ВСЕХ объектов. от него начледуются почти все логические элементы (косвенно или напрямую)
/// @tparam TypeSystem - система типов, к которой будет принадлежать объект (типы игрового процесса или объекты меню например)
template <typename TypeSystem>
class Obj {
public:
    using pair_ui64_t = std::pair<uint64_t, uint64_t>;
protected:
    pair_ui64_t size = std::make_pair(0, 0);
    pair_ui64_t repeate = std::make_pair(1, 1);
    pair_ui64_t position = std::make_pair(0, 0);
    char layer = 0;
    bool is_static = true;

    Collider collider;
    std::string name;
    bool obj_exist = true;
public:
    Obj() = default;
    Obj(std::string name, pair_ui64_t position);
    Obj(const Obj &) = default;
    virtual ~Obj() {}

    virtual void read(std::ifstream & ) = 0;
public:
    bool exist()
    { return obj_exist; }
    // void move(int x, int y);

    bool is_mobile()
    { return collider.mobility; }
    void move(int x, int y) {
        position.first += x;
        position.second += y;
    }

    //============= getters =============//

    char get_layer() const { return layer; }

    const std::string & get_name() const { return name; }
    
    bool get_static() { return is_static; }

    double get_v_angle() const { return collider.moving_angle; }

    double get_velocity() const { return collider.velocity; }

    size_t x_rep() { return repeate.first;  }
    size_t y_rep() { return repeate.second; }

    pair_ui64_t get_position() const { return position; }

    pair_ui64_t get_size() const { return size; }

    virtual TypeSystem get_type() const = 0;

    //============= setters ==============//

    void set_velocity(double v) { collider.velocity = v; }

    void set_v_angle(double a) { collider.moving_angle = a; }

    void set_exist(bool ex) { obj_exist = ex; }

    void set_size(pair_ui64_t s) { size = s; }

    void set_position(pair_ui64_t p) { position = p; }
    
    void set_static(bool st) { is_static = st; }

private:
    TypeSystem type;
};

#endif