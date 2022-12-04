#ifndef BACK_PACK_STORE_CLASS
#define BACK_PACK_STORE_CLASS

#include "BPMObject.hpp"
#include "../containers/Container.hpp"
#include "SFML/Graphics.hpp"
#include "../constants.hpp"
#include "../World.hpp"

#include <vector>
#include <algorithm>
#include <map>

class BackPackStore : public BPMObj {
protected:
    Container & container;
    sf::RectangleShape rect_field = sf::RectangleShape(sf::Vector2f(120, 30));
    const size_t cols{10}, rows{10};
    size_t W{}, H{};
    std::vector <std::vector <std::shared_ptr <BPMObj>>> things;
    const std::map<GameTypeSystem, ObjTextureStore> * ts;
    size_t number_of_things{};
public:
    size_t get_W() const { return W; }
    size_t get_H() const { return H; }
    BackPackStore(Container & c) : container(c) {
        rect_field.setFillColor(msc::MyDarkSlateBlue);
    }
    BackPackStore(std::string n, pair_ui64_t p, Container & c) : container(c) {
        position = p;
        name = n;
    }
    ~BackPackStore() {}

protected:
    class Cell : public BPMObj {
    protected:
        const BackPackStore & bp;
        std::shared_ptr<GameObj> obj;
    public:
        Cell(const BackPackStore & bps, const GameObj & obj) : bp(bps) {
            // this->set_texture(textures.bp_texture, std::make_pair(bps.get_W(), bps.get_H()));
            textures.current_texture = textures.bp_texture;
            position = obj.get_position();
            layer = obj.get_layer();
            name = obj.get_name();
            size = obj.get_size();
        }
        BackPackTypeSystem get_type() const override
        { return CELL; }
        void edit(const Alive & a) override {}
        void draw(sf::RenderWindow & window) const override {
            window.draw(sprite);
        }
        void read(std::ifstream & ) override {}
    };

public:
    BackPackTypeSystem get_type() const override
    { return BACK_PACK_STORE; }
    void set_textures(World & w)
    { ts = &w.get_texture_store(); }
    void edit(const Alive & a) override {
        try {
            [[maybe_unused]] const Character & hero = dynamic_cast<const Character &>(a);
        } catch(...) {
            throw;
        }
        const Character & hero = dynamic_cast<const Character &>(a);
        things.clear();
        things.resize(rows);
        for (size_t i = 0; i < rows; ++i)
            things[i].resize(cols);

        const std::vector <std::shared_ptr<GameObj>> & all_things = hero.get_backpack().get_things();
        if (cols*rows < all_things.size()) {
            std::cout << "there is too many things in this backpack!" << std::endl;
            throw std::invalid_argument("too many things");
        }
        number_of_things = all_things.size();

        size_t g_ind = 0;
        sf::FloatRect bounds = rect_field.getGlobalBounds();
        size_t cell_w{W/cols}, cell_h{H/rows};
        for (size_t i = 0, l = all_things.size(); i < rows; ++i) {
            for (size_t j = 0; j < cols && g_ind < l; ++j, ++g_ind) {
                things[i][j] = std::make_shared<BackPackStore::Cell>(*this, *all_things[g_ind]);
                things[i][j]->set_size(std::make_pair(cell_w, cell_h));

                size_t x{(size_t) bounds.getPosition().x + cell_w * j}, y{(size_t) bounds.getPosition().y + cell_h * i};
                things[i][j]->set_position(std::make_pair(x, y));
                GameTypeSystem type = all_things[g_ind]->get_type();
                things[i][j]->set_texture(ts->at(type).bp_texture, things[i][j]->get_size());
                things[i][j]->set_sprite_position(std::make_pair(x, y));
            }
        }
    }
    void draw(sf::RenderWindow & window) const override {
        // draw the field - platform for cells with things
        window.draw(rect_field);
        // draw the grid / create cells
        DrawFunctions::drawGrid(window, cols, rows, rect_field.getGlobalBounds());
        size_t g_i{};
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                // window.clear(sf::Color::Black);
                things[i][j]->draw(window);
                ++g_i;
                if (g_i >= number_of_things)
                    break;
            }
            if (g_i >= number_of_things)
                break;
        }
    }
    void read(std::ifstream & ) override {}
    void set_size(pair_ui64_t size) {
        rect_field.setSize(sf::Vector2f(size.first, size.second));
        W = size.first;
        H = size.second;
    }
    void set_position(const pair_ui64_t & p) {
        rect_field.setPosition(sf::Vector2f(p.first, p.second));
    }
};

#endif