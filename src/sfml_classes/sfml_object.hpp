#ifndef SFML_OBJECTS_CLASS
#define SFML_OBJECTS_CLASS

#include <algorithm>

#include "../objects/GameObject.hpp"

class SFMLObject {
protected:
    std::shared_ptr<GameObj> obj;
    char layer = 0;
    pair_ui64_t w_position = std::make_pair(0, 0);
    sf::Sprite sprite;
    ObjTextureStore & textures;
    std::shared_ptr<sf::Texture> current_texture;

    sf::Clock clock;
    sf::Time period;
    sf::Time life_time;
public:
    // void set_texture(fs::path file_path, std::pair<unsigned int, unsigned int> p_in, std::pair<unsigned int, unsigned int> scale, std::pair<unsigned int, unsigned int> n_repeat);
    // void set_texture(std::shared_ptr<sf::Texture> t, pair_ui64_t size);
    void update_texture() {
        sf::Time ex_time = clock.getElapsedTime();
        size_t n_o_states = textures.textures.size();
        if (ex_time.asMilliseconds() % period.asMilliseconds() > period.asMilliseconds() / sf::Time(ex_time).asMilliseconds()) {
            this->set_texture(textures.textures[(ex_time.asMilliseconds() % period.asMilliseconds())/(period.asMilliseconds()/n_o_states)], std::make_pair(1, 1));
        }
    }
    void set_period(sf::Time t)
    { period = t; }
    void set_life_time(sf::Time t)
    { life_time = t; }
    sf::Time get_period()
    { return period; }
    sf::Time get_life_time()
    { return life_time; }
    sf::Clock & get_clock()
    { return clock; }
    sf::Time get_time()
    { return clock.getElapsedTime(); }
    void restart_clock()
    { clock.restart(); }
    char get_layer() const
    { return layer; }
    ObjTextureStore & get_ts()
    { return textures; }

    SFMLObject(std::shared_ptr<GameObj> o, ObjTextureStore & t, char l = 0) : obj(o), layer(l), textures(t) {

    }
    ~SFMLObject() {}

    std::shared_ptr<GameObj> get_obj()
    { return obj; }

    const sf::Sprite & get_sprite() const
    { return sprite; }
    sf::Sprite & get_sprite()
    { return sprite; }
    sf::Sprite get_sprite_copy() const
    { return sprite; }
    const std::shared_ptr<sf::Texture> & get_texture() const
    { return textures.current_texture; }

    void set_texture(fs::path file_path, std::pair<unsigned int, unsigned int> p_in, std::pair<unsigned int, unsigned int> scale, std::pair<unsigned int, unsigned int> n_repeat) {
        textures.current_texture = std::make_unique<sf::Texture>();
        *textures.current_texture = sf::Texture();
        if (n_repeat.first || n_repeat.second) {
            textures.current_texture->setRepeated(true);
        }
        sf::Vector2 position_in((int) p_in.first, (int) p_in.second);
        sf::Vector2 size_f((float) (scale.first * n_repeat.first), (float) (scale.second * n_repeat.second));
        sf::Vector2 size_i((int) (scale.first), (int) (scale.second));
        sf::Vector2 size_r((int) (scale.first * n_repeat.first), (int) (scale.second * n_repeat.second));
        if (!textures.current_texture->loadFromFile(static_path / file_path, sf::IntRect(position_in, size_i))) {
            std::cout << "cannot read texture from file : " << file_path << std::endl;
            throw std::invalid_argument("there is not such file with texture");
        }

        sprite.setTexture(*textures.current_texture);
        if (n_repeat.first || n_repeat.second) {
            sprite.setTextureRect(sf::IntRect(sf::Vector2(0, 0), size_r));
        }
    }
    void set_texture(std::shared_ptr<sf::Texture> t, pair_ui64_t size) {
        textures.current_texture = t;
        sprite.setTexture(*t);
        sprite.scale(sf::Vector2f((double)size.first/(double)t->getSize().x, (double)size.second/(double)t->getSize().y));
    }

    void set_position(const pair_ui64_t & p) {
        obj->set_position(p);
        // sf::Vector2 p_v((float) p.first, (float) p.second);
    }

    void set_sprite_position(pair_ui64_t p) {
        sf::Vector2 p_v((float) p.first, (float) p.second);
        sprite.setPosition(p_v);
    }

    void draw(sf::RenderWindow & w) const
    { w.draw(sprite); }
};

#endif // SFML_OBJECTS_CLASS