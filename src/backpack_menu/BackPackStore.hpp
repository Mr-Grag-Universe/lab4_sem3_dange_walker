#ifndef BACK_PACK_STORE_CLASS
#define BACK_PACK_STORE_CLASS

#include "BPMObject.hpp"
#include "../containers/Container.hpp"
#include "SFML/Graphics.hpp"
#include "../constants.hpp"

class BackPackStore : public BPMObj {
protected:
    Container & container;
    sf::RectangleShape rect_field = sf::RectangleShape(sf::Vector2f(120, 30));
public:
    BackPackStore(Container & c) : container(c) {
        rect_field.setFillColor(MyDarkSlateBlue);
    }
    BackPackStore(std::string n, pair_ui64_t p, Container & c) : container(c) {
        position = p;
        name = n;
    }
    ~BackPackStore() {}

    BackPackTypeSystem get_type() const override
    { return BACK_PACK_STORE; }
    void edit(const Alive &) override {}
    void draw(sf::RenderWindow & window) const override {
        window.draw(rect_field);
    }
    void read(std::ifstream & ) override {}
    void set_size(pair_ui64_t size) {
        rect_field.setSize(sf::Vector2f(size.first, size.second));
    }
    void set_position(const pair_ui64_t & p) {
        rect_field.setPosition(sf::Vector2f(p.first, p.second));
    }
};

#endif