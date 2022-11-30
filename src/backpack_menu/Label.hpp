#ifndef LABEL_CLASS
#define LABEL_CLASS

#include "BPMObject.hpp"
#include "../alive_obj/Alive.hpp"
#include "../constants.hpp"
#include <SFML/Graphics.hpp>

class Label : public BPMObj {
protected:
    std::string s_text;
    sf::RectangleShape field = sf::RectangleShape(sf::Vector2f(120, 30));
    sf::Font font;
    sf::Text text;
public:
    Label(std::string t, pair_ui64_t size = std::make_pair(120, 30), size_t t_size=24) {
        if (!font.loadFromFile(static_path / "ArialRegular.ttf")) {
            throw std::runtime_error("we cannot load arial");
        }
        s_text = std::string(t);
        field.setSize(sf::Vector2f((float) size.first, (float) size.second));
        // text = sf::Text(s_text, font, 24);
        // text.setCharacterSize(t_size);
        text.setPosition(middle_rect_pos(field, text.getGlobalBounds().getSize()));
    }

    BackPackTypeSystem get_type() const override
    { return LABEL; }
    void read(std::ifstream & ) override {}
    void draw(sf::RenderWindow & window) const override {
        window.draw(field);
        window.draw(text);
    }
    void edit(const Alive & a) override {}

    void set_label_size(pair_ui64_t s) {
        size = s;
        field.setSize(sf::Vector2f(s.first, s.second));
        // text.setSize(sf::Vector2f(s.first, s.second));
    }
    void set_text_size(size_t s)
    { text.setCharacterSize(s); }
    void set_font(sf::Font & f) {
        font = f;
        text.setFont(font);
    }
    void set_text(std::string t) {
        s_text = t;
        // text.setFont(font);
        text.setString(t);
    }
    void set_position(pair_ui64_t p) {
        position = p;
        field.setPosition(sf::Vector2f(p.first, p.second));
        text.setPosition(middle_rect_pos(field, sf::Vector2f(p.first, p.second)));
    }
};

#endif