#ifndef CHAR_BAR_CLASS
#define CHAR_BAR_CLASS

#include "BPMObject.hpp"
#include "../alive_obj/Character.hpp"
#include "../constants.hpp"
#include "Label.hpp"
#include "StatusBar.hpp"

/// @brief  scale of something: visualisation of percents ([########################------------65%])
/// @tparam AliveType - type of the Creature, which characteristics we show
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
    std::vector <StatusBar<double>> status_bars;
    std::vector <Label> statistic;
    size_t W{}, H{};
public:
    CharBar(const Character & c) : alive(c) {
        health = c.get_helth();
        max_health = c.get_max_health();
        exp = c.get_exp();
        max_exp = c.get_max_exp();
        name = c.get_name();

        std::cout << "alive char bar created" << alive.get_name() << "\n";
        rect_field.setFillColor(msc::MyDarkSlateBlue);
        status_bars.push_back(StatusBar<double>(max_health, health));
        status_bars[0].set_label("health");
        status_bars[0].set_scale_color(sf::Color::Green);
        status_bars.push_back(StatusBar<double>(max_exp, exp));
        status_bars[1].set_label("exp");
        status_bars[1].set_scale_color(sf::Color::Blue);

        statistic.push_back(Label(std::to_string(c.get_level())));
    }
    ~CharBar() {}
    BackPackTypeSystem get_type() const override
    { return CHAR_BAR; }
    void read(std::ifstream & ) override {}
    void draw(sf::RenderWindow & window) const override {
        window.draw(rect_field);
        for (auto sb: status_bars)
            sb.draw(window);
        for (auto st: statistic)
            st.draw(window);
        // status_bars[1].draw(window);
        // window.draw(rect_health_field);
        // window.draw(rect_exp_field);
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

        statistic[0].set_text(std::to_string(level));
        statistic[0].get_text().setFillColor(sf::Color::Magenta);

        std::cout << "char bar eddition completed" << std::endl;
    }
    void set_size(pair_ui64_t size) {
        this->size = size;
        rect_field.setSize(sf::Vector2f(size.first, size.second));
        for (auto & sb: status_bars)
            sb.set_size(std::make_pair(size.first-20, size.second/4-20));
        for (auto & st: statistic)
            st.set_label_size(std::make_pair(size.first-20, size.second/4-20));
        W = size.first;
        H = size.second;
    }
    void set_position(const pair_ui64_t & p) {
        rect_field.setPosition(sf::Vector2f(p.first, p.second));
        for (size_t i = 0; i < status_bars.size(); ++i)
            status_bars[i].set_position(std::make_pair(p.first+10, p.second+10*(i+1) + i*H/4));
        for (size_t i = 0; i < statistic.size(); ++i)
            statistic[i].set_position(std::make_pair(p.first+10, p.second+10*(status_bars.size()+i+1) + (status_bars.size()+i)*H/4));
        position = p;
    }
};

#endif