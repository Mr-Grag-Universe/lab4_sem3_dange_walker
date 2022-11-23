#include "Sward.hpp"



Sward::Sward(std::string n, int d, size_t r) {
    name = n;
    damage = d;
    radius = r;
}
Sward::Sward(std::string n, std::pair<unsigned int, unsigned int> p) {
    position = p;
    name = n;
}

void Sward::read(std::ifstream & file) {
    file >> name;
    file >> damage;
    file >> radius;
    size = std::make_pair(20, 20);
    // std::shared_ptr<Obj> res = std::make_shared<Sward>(name, damage, radius);
    // return res;
}

std::shared_ptr<MW_Wave> Sward::wave(double r, Alive & o) {
    MW_Wave wave(r, o, damage);
    // TextureStore & ts = w.get_effect_texture(MW_WAVE);
    // wave.set_position(o.get_position());
    // wave.set_texture(ts.textures[0]);
    // wave.set_period(ts.period);
    // wave.set_life_time(ts.life_time);
    // sf::Vector2 p_v((float) 1910/2, (float) 1080/2);
    // sprite.setPosition(p_v);
    // w.add_effect(std::make_shared<MW_Wave>(wave));
    return std::make_shared<MW_Wave>(wave);
}

std::shared_ptr<Effect> Sward::use(Alive & o) {
    return wave(radius, o);
}