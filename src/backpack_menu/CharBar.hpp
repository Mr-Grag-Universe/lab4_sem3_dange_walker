#ifndef CHAR_BAR_CLASS
#define CHAR_BAR_CLASS

#include "BPMObject.hpp"
#include "../alive_obj/Character.hpp"
#include "../constants.hpp"

template <typename AliveType = Alive>
class CharBar : public BPMObj {
private:
    const AliveType & alive;
    float health{};
    std::string name;
public:
    CharBar(const AliveType & a) : AliveType(a) {
        health = a.get_helth();
        name = a.get_name();
    }
    ~CharBar() {}
    BackPackTypeSystem get_type() const override
    { return CHAR_BAR; }
    void read(std::ifstream & ) override {}
    void draw(sf::RenderWindow & window) const override {}
    void edit(const Alive & a) override {}
};

template <>
class CharBar<Character> : public BPMObj {
private:
    const Character & alive;
    double health{}, max_health{};
    std::string name;
    size_t exp{}, max_exp{};
    size_t level{};
    sf::RectangleShape rect_field = sf::RectangleShape(sf::Vector2f(120, 30));
    sf::RectangleShape rect_health_field = sf::RectangleShape(sf::Vector2f(120, 30));
    sf::RectangleShape rect_exp_field = sf::RectangleShape(sf::Vector2f(120, 30));
    size_t W{}, H{};
public:
    CharBar(const Character & c) : alive(c) {
        health = c.get_helth();
        max_health = c.get_max_health();
        name = c.get_name();
        std::cout << "alive char bar created" << alive.get_name() << "\n";
        rect_field.setFillColor(MyDarkSlateBlue);
    }
    ~CharBar() {}
    BackPackTypeSystem get_type() const override
    { return CHAR_BAR; }
    void read(std::ifstream & ) override {}
    void draw(sf::RenderWindow & window) const override {
        window.draw(rect_field);
        window.draw(rect_health_field);
        window.draw(rect_exp_field);
    }
    void edit(const Alive & a) override {
        std::cout << "char bar eddition" << std::endl;
        try {
            [[maybe_unused]] const Character & hero = dynamic_cast<const Character &>(a);
        } catch(...) {
            throw;
        }
        const Character & hero = dynamic_cast<const Character &>(a);
        name = hero.get_name();
        exp = hero.get_exp();
        max_exp = hero.get_max_exp();
        health = hero.get_helth();
        level = hero.get_level();
        std::cout << "char bar eddition completed" << std::endl;
    }
    void set_size(pair_ui64_t size) {
        this->size = size;
        rect_field.setSize(sf::Vector2f(size.first, size.second));
        rect_health_field.setSize(sf::Vector2f(size.first-20, size.second/4-20));
        rect_exp_field.setSize(sf::Vector2f(size.first-20, size.second/4-20));
        W = size.first;
        H = size.second;
    }
    void set_position(const pair_ui64_t & p) {
        rect_field.setPosition(sf::Vector2f(p.first, p.second));
        rect_health_field.setPosition(sf::Vector2f(p.first+10, p.second+10));
        rect_exp_field.setPosition(sf::Vector2f(p.first+10, p.second+rect_health_field.getSize().y+20));
        position = p;
    }
};

#endif