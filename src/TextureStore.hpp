#ifndef TEXTURE_STORE_CLASS
#define TEXTURE_STORE_CLASS

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


struct ObjTextureStore {
    std::vector <std::shared_ptr<sf::Texture>> textures;
    std::shared_ptr<sf::Texture> current_texture;
    std::shared_ptr<sf::Texture> preview;
    std::shared_ptr<sf::Texture> bp_texture;

    sf::Clock standard_clock;
    sf::Time standard_period;
    sf::Time standard_life_time;

    std::vector<std::shared_ptr<sf::SoundBuffer>> sounds;

    bool is_static = true;
};

class TextureStore {
private:
    // std::map<GameTypeSystem, ObjTextureStore> game_obj_textures;
public:
    TextureStore();
    ~TextureStore();
};

#endif // TEXTURE_STORE_CLASS