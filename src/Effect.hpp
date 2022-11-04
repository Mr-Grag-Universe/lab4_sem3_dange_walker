#ifndef EFFECT_CLASS
#define EFFECT_CLASS

#include "Object.hpp"

// интерфейс эффекта
class Effect : public Obj {
private:
    sf::Clock clock;
public:
    virtual bool makes_damage() const = 0;
    virtual const Alive & get_originator_ptr() const = 0;
    Effect() {};
    ~Effect() {};
    Effect(const Effect &) = default;

    void set_texture(std::shared_ptr<sf::Texture> t) {
        sprite.setTexture(*t);
    }

    virtual void make_damage(Alive &) = 0;

    sf::Clock & get_clock()
    { return clock; }
    sf::Time get_time()
    { return clock.getElapsedTime(); }
    void restart_clock()
    { clock.restart(); }
};

#endif