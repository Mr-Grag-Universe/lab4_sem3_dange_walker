#ifndef SFML_OBJECTS_CLASS
#define SFML_OBJECTS_CLASS

#include "GameObjects.hpp"

class SFMLObject : GameObj {
protected:
    pair_ui64_t w_position = std::make_pair(0, 0);
    sf::Sprite sprite;
    ObjTextureStore textures;
    // std::shared_ptr<sf::Texture> texture = nullptr;
    unsigned char layer = 0;
public:
    SFMLObject() {}
    ~SFMLObject() {}
};

#endif // SFML_OBJECTS_CLASS