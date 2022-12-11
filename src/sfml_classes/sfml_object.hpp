#ifndef SFML_OBJECTS_CLASS
#define SFML_OBJECTS_CLASS

#include <algorithm>
#include <ctime>

#include "../objects/GameObject.hpp"
#include "sfml_sound.hpp"

/// @brief класс для отрисовки. прослойка между логикой и отрисовкой
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

    bool is_static = true;

    SFMLSound sound;
public:
    bool isstatic() const
    { return is_static; }
    void set_static(bool s)
    { is_static = s; }
    void process_sound_queue() {
        std::queue q = obj->extract_sound_queue();
        if (q.size()) {
            while (q.size()) {
                size_t ind = q.front();
                sound.play(ind);
                q.pop();
            }
        }
    }
    void set_sounds(std::vector<std::shared_ptr<sf::SoundBuffer>> & sb) {
        if (sb.empty())
            throw std::invalid_argument("emty vector of sound buffers have been passed");
        sound = SFMLSound(sb);
        std::cout << "souns've been loaded to sfml object" << std::endl;
    }
    std::vector <std::shared_ptr<sf::Sound>> create_sounds(std::vector<std::shared_ptr<sf::SoundBuffer>> & sb) {
        std::queue q = obj->extract_sound_queue();
        std::vector <std::shared_ptr<sf::Sound>> s;
        if (q.size()) {
            while (q.size()) {
                size_t ind = q.front();
                s.push_back(std::make_shared<sf::Sound>(*sb[ind]));
                // s.front()->setBuffer(*sb[ind]);
                q.pop();
            }
        }
        return s;
    }

    static size_t calculate_phase(sf::Time period, std::chrono::time_point<std::chrono::steady_clock> was_born, size_t n_o_ph) {
        size_t p = (size_t) period.asMilliseconds();
        auto ex_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - was_born);
        size_t ex_time = (size_t) sf::milliseconds(ex_time_.count()).asMilliseconds();// sf::microseconds((std::chrono::steady_clock::now() - obj->get_born()).count()).asMilliseconds();
        return ((ex_time % p) * n_o_ph) / p;
    }

    // инверсия зависимостей
    // а. класс
    // по сути прослойка
    void update_texture() {
        if (is_static)
            return;
        // sf::Time ex_time = sf::milliseconds((double) (std::clock() - obj->get_born()) * 30 / CLOCKS_PER_SEC * 1000);
        auto ex_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - obj->get_born());
        // std::cout << ex_time_;
        sf::Time ex_time = sf::milliseconds(ex_time_.count());
        // std::cout << life_time.asMilliseconds() << "ms; " << ex_time.asMilliseconds() << "ms\n";
        // std::cout << (double)std::clock() / CLOCKS_PER_SEC << "s; " << obj->get_phase() << "\n";
        size_t n_o_states = textures.textures.size();
        if (ex_time.asMilliseconds() > life_time.asMilliseconds() && life_time.asMilliseconds() != sf::seconds(0).asMilliseconds()) {
            obj->set_exist(false);
            return;
        }
        if (n_o_states > 1 && period.asMilliseconds() != sf::seconds(0).asMilliseconds()) { // (ex_time.asMicroseconds() % period.asMicroseconds() > period.asMicroseconds() / (ex_time.asMicroseconds())) {
            size_t p = calculate_phase(period, obj->get_born(), n_o_states); // ((ex_time.asMicroseconds() % period.asMicroseconds()) * n_o_states)/(period.asMicroseconds());
            [[maybe_unused]] GameTypeSystem type = obj->get_type();
            if (p != obj->get_phase()) {
                this->correct_phase();
                // std::cout << "=========================================" << obj->get_phase() << "\n";
                current_texture = textures.textures[p];
            }
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
        current_texture = textures.textures[0];
        // obj->set_phase((size_t) sf::seconds((double) (std::clock()-obj->get_born()) / CLOCKS_PER_SEC).asMilliseconds() * obj->get_number_of_phases() / (size_t) period.asMilliseconds());
    }
    void correct_phase() {
        size_t p = (size_t) period.asMilliseconds();
        size_t n_o_ph = obj->get_number_of_phases();
        // size_t ex_time = (size_t) sf::seconds((double) (std::clock() - obj->get_born()) / CLOCKS_PER_SEC).asMilliseconds();
        auto ex_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - obj->get_born());
        size_t ex_time = (size_t) sf::milliseconds(ex_time_.count()).asMilliseconds();// sf::microseconds((std::chrono::steady_clock::now() - obj->get_born()).count()).asMilliseconds();
        obj->set_phase(((ex_time % p) * n_o_ph) / p);
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
        current_texture = std::make_unique<sf::Texture>();
        // *textures.current_texture = sf::Texture();
        if (n_repeat.first || n_repeat.second) {
            current_texture->setRepeated(true);
        }
        sf::Vector2 position_in((int) p_in.first, (int) p_in.second);
        sf::Vector2 size_f((float) (scale.first * n_repeat.first), (float) (scale.second * n_repeat.second));
        sf::Vector2 size_i((int) (scale.first), (int) (scale.second));
        sf::Vector2 size_r((int) (scale.first * n_repeat.first), (int) (scale.second * n_repeat.second));
        if (!current_texture->loadFromFile(mp::img / file_path, sf::IntRect(position_in, size_i))) {
            std::cout << "cannot read texture from file : " << file_path << std::endl;
            throw std::invalid_argument("there is not such file with texture");
        }

        sprite.setTexture(*textures.current_texture);
        if (n_repeat.first || n_repeat.second) {
            sprite.setTextureRect(sf::IntRect(sf::Vector2(0, 0), size_r));
        }
    }
    void set_texture(std::shared_ptr<sf::Texture> t, pair_ui64_t size) {
        current_texture = t;
        sprite = sf::Sprite();
        if (obj->x_rep() != 1 || obj->y_rep() != 1) {
            // current_texture = std::make_shared<sf::Texture>();
            // // *current_texture = t->(sf::Vector2u(size.first*obj->x_rep(), size.second*obj->y_rep()));
            current_texture->setRepeated(true);
            // if (!current_texture->loadFromImage(t->copyToImage())) {
            //     std::cout << "someting bad in coping of imagine" << std::endl;
            // }
        } else {
            sprite.setTexture(*current_texture);
        }
        sf::Vector2 size_r((int) (size.first * obj->x_rep()), (int) (size.second * obj->y_rep()));
        sprite.setTexture(*current_texture);
        sprite.setTextureRect(sf::IntRect(sf::Vector2(0, 0), size_r));
        // std::cout << obj->x_rep() << " " << obj->y_rep() << "\n";
        std::pair<double, double> scale = std::make_pair((double)size.first/(double)t->getSize().x, (double)size.second/(double)t->getSize().y);
        sprite.scale(sf::Vector2f(scale.first, scale.second));
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