#ifndef STATUS_BAR_CLASS
#define STATUS_BAR_CLASS

#include "BPMObject.hpp"
#include "../alive_obj/Character.hpp"
#include "../constants.hpp"
#include "Label.hpp"

template <typename T = size_t>
class StatusBar : public BPMObj {
protected:
    sf::RectangleShape field = sf::RectangleShape(sf::Vector2f(120, 30));
    sf::RectangleShape scale = sf::RectangleShape(sf::Vector2f(120, 30));
    T max_value;
    T value;
    Label label = Label("char_bar");

public:
    StatusBar() {}
    StatusBar(T m_val, T val) : max_value(m_val), value(val) {
        label.set_text("char_bar1");
    }
    void set_values(T m_val, T val) {
        max_value = m_val;
        value = val;
    }
    void set_size(pair_ui64_t s) {
        field.setSize(sf::Vector2f(s.first, s.second));
        scale.setSize(sf::Vector2f(s.first*((double) value / (double) max_value), s.second));
        label.set_size(std::make_pair(s.first/10, s.second));
    }
    void set_position(pair_ui64_t p) {
        field.setPosition(sf::Vector2f(p.first, p.second));
        scale.setPosition(sf::Vector2f(p.first, p.second));
        label.set_position(p);
    }
    void set_field_color(sf::Color color) {
        field.setFillColor(color);
    }
    void set_scale_color(sf::Color color) {
        scale.setFillColor(color);
    }
    void set_color(sf::Color field_color, sf::Color scale_color) {
        field.setFillColor(field_color);
        scale.setFillColor(scale_color);
    }
    void set_label(std::string l) {
        label.set_text(l);
    }
    // void set_sprite_position()

    BackPackTypeSystem get_type() const override
    { return STATUS_BAR; }
    void read(std::ifstream & ) override {}
    void draw(sf::RenderWindow & window) const override {
        window.draw(field);
        window.draw(scale);
        // label.draw(window);
    }
    void edit(const Alive & a) override {}
};

#endif