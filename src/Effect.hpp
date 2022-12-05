#ifndef EFFECT_CLASS
#define EFFECT_CLASS

#include "objects/Object.hpp"
#include "constants.hpp"

/// интерфейс эффекта
class Effect;
class Effect : public GameObj {
protected:
public:
    virtual bool makes_damage() const = 0;
    virtual const Alive & get_originator_ptr() const = 0;
    Effect() {}
    ~Effect() {};
    Effect(const Effect &) = default;

    // void set_texture(std::shared_ptr<sf::Texture> t) {
    //     sprite.setTexture(*t);
    // }

    virtual void make_damage(Alive &) = 0;
    virtual void iterate() = 0;
};

#endif