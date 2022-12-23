#ifndef SFML_MESSAGE_CLASS
#define SFML_MESSAGE_CLASS

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../constants.hpp"
#include "../sfml_classes/sfml_object.hpp"

class SFML_Message
{
private:
protected:
    sf::RectangleShape field = sf::RectangleShape(sf::Vector2f(100, 100));
    std::string s_text = "empty message";
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    sf::Text text;
    std::shared_ptr<sf::Texture> field_texture = nullptr;
public:
    // SFML_Message(std::string message) : s_text(message) {}
    SFML_Message(std::string t, pair_ui64_t size = std::make_pair(120, 30), size_t t_size=24) {
        if (!font->loadFromFile(mp::font / "ArialRegular.ttf")) {
            throw std::runtime_error("we cannot load arial");
        }
        s_text = std::string(t);
        field.setSize(sf::Vector2f((float) size.first, (float) size.second));
        text.setPosition(middle_rect_pos(field, sf::Vector2f(0.0, 0.0)));
    }

    void read(std::ifstream & ) {}
    void draw(sf::RenderWindow & window) const {
        window.draw(field);
        window.draw(text);
    }
    void edit(const Alive & a) {}

    //============ getters ============//

    sf::Text & get_text()
    { return text; }

    sf::RectangleShape & get_field()
    { return field; }

    BackPackTypeSystem get_type() const
    { return LABEL; }

    //============ setters ============//

    void set_label_size(pair_ui64_t s) {
        // size = s;
        field.setSize(sf::Vector2f(s.first, s.second));
        text.setCharacterSize(20);
    }

    void set_text_size(size_t s)
    { text.setCharacterSize(s); }

    void set_font(std::shared_ptr<sf::Font> f) {
        font = f;
        text.setFont(*font);
    }

    void set_text(std::string t) {
        s_text = t;
        text.setFont(*font);  //?
        text.setString(s_text);
    }
    void set_position(pair_ui64_t p) {
        // position = p;
        field.setPosition(sf::Vector2f(p.first-field.getSize().x/2, p.second-field.getSize().y/2));
        sf::Vector2f size = field.getSize();
        size.x = size.x - size.x/8;
        size.y = size.y - size.y/8;
        text.setPosition(middle_rect_pos(field, size));
    }

    void set_text_color(sf::Color color)
    { text.setFillColor(color); }

    void set_field_color(sf::Color color)
    { field.setFillColor(color); }

    void set_field_texture(std::shared_ptr<sf::Texture> t)
    { field_texture = t; field.setTexture(&(*field_texture)); }
};

#endif // SFML_MESSAGE_CLASS