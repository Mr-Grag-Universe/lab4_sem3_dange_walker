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

    // std::shared_ptr<Obj> res = std::make_shared<Sward>(name, damage, radius);
    // return res;
}

std::shared_ptr<MW_Wave> Sward::wave(World & w, double r, Alive & o) {
    MW_Wave wave(w, r, o, damage);
    wave.set_position(o.get_position());
    wave.set_texture(w.get_effect_texture(MW_WAVE).textures[0]);
    sf::Vector2 p_v((float) 1910/2, (float) 1080/2);
    sprite.setPosition(p_v);
    // w.add_effect(std::make_shared<MW_Wave>(wave));
    return std::make_shared<MW_Wave>(wave);
}

std::shared_ptr<Effect> Sward::use(World & w, Alive & o) {
    return wave(w, radius, o);
}