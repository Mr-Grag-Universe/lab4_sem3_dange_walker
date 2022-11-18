#ifndef SKIN_CLASS
#define SKIN_CLASS

#include "BPMObject.hpp"
#include "../constants.hpp"
#include "../alive_obj/Character.hpp"
#include <SFML/Graphics.hpp>

class Skin : public BPMObj {
private:
    size_t level = 0;
    std::string char_name;
public:
    Skin() {}
    Skin(std::string n, pair_ui64_t p) {
        position = p;
        name = n;
    }
    // Skin(const Skin && s) {
    //     position = s.position;
    //     name = s.name;
    //     texture = s.texture;
    //     sprite = s.sprite;
    //     layer = s.layer;
    // }
    // Skin(const Skin & s) {
    //     position = s.position;
    //     name = s.name;
    //     texture = s.texture;
    //     sprite = s.sprite;
    //     layer = s.layer;
    // }
    BackPackTypeSystem get_type() const override
    { return SKIN; }
    void read(std::ifstream & ) override {
    }
    void draw(sf::RenderWindow & window) const override{
        window.draw(sprite);
        sf::RectangleShape rectangle(sf::Vector2f(120, 30));
        rectangle.setSize(sf::Vector2f(200, 50));
        rectangle.setFillColor(MyDarkSlateBlue);
        sf::FloatRect rect = sprite.getGlobalBounds();
        sf::Vector2 p = rect.getPosition();
        sf::Vector2f ss = rect.getSize();
        sf::Vector2f s = rectangle.getSize();
        p.x += (ss.x-s.x)/2;
        p.y += (ss.y-s.y);
        rectangle.setPosition(p);

        sf::Font font;
        if (!font.loadFromFile(static_path / "ArialRegular.ttf")) {
            throw std::runtime_error("we cannot load arial");
        }
        sf::Text text;
        text.setFont(font);
        text.setString("Stepan");
        text.setCharacterSize(24);
        text.setPosition(middle_rect_pos(rectangle, text.getGlobalBounds().getSize()));

        // rectangle.getLocalBounts();
        window.draw(rectangle);
        window.draw(text);
    }
    void edit(const Alive & a) override {
        try {
            [[maybe_unused]] const Character & hero = dynamic_cast<const Character &>(a);
        } catch(...) {
            throw;
        }
        const Character & hero = dynamic_cast<const Character &>(a);
        char_name = hero.get_name();
        level = hero.get_level();
    }
private:
    [[maybe_unused]] BackPackTypeSystem type = SKIN;
};

#endif