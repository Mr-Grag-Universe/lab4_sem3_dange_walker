#ifndef EFFECT_CLASS
#define EFFECT_CLASS

#include "Object.hpp"
#include "World.hpp"
#include "constants.hpp"

// интерфейс эффекта
class Effect;
class Effect : public Obj<GameTypeSystem> {
protected:
    sf::Clock clock;
    sf::Time period;
    sf::Time life_time;
    TextureStore & ts;
public:
    virtual bool makes_damage() const = 0;
    virtual const Alive & get_originator_ptr() const = 0;
    void update_texture() {
        sf::Time ex_time = clock.getElapsedTime();
        size_t n_o_states = ts.textures.size();
        // if (ex_time.asMilliseconds() % period.asMilliseconds() > period.asMilliseconds() / sf::Time(ex_time).asMilliseconds()) {
        this->set_texture(ts.textures[(ex_time.asMilliseconds() % period.asMilliseconds())/(period.asMilliseconds()/n_o_states)]);
        //}
    }
    Effect(TextureStore & t) : ts(t) {};
    Effect(TextureStore & t, sf::Time p, sf::Time lt) : period(p), life_time(lt), ts(t) {};
    ~Effect() {};
    Effect(const Effect &) = default;

    void set_texture(std::shared_ptr<sf::Texture> t) {
        sprite.setTexture(*t);
    }
    void set_period(sf::Time t)
    { period = t; }
    void set_life_time(sf::Time t)
    { life_time = t; }

    virtual void make_damage(Alive &) = 0;

    sf::Time get_period()
    { return period; }
    sf::Time get_life_time()
    { return life_time; }

    sf::Clock & get_clock()
    { return clock; }
    sf::Time get_time()
    { return clock.getElapsedTime(); }
    void restart_clock()
    { clock.restart(); }
};

#endif