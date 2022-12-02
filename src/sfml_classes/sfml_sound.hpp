#ifndef SFML_SOUNDS_CLASS
#define SFML_SOUNDS_CLASS

#include <SFML/Audio.hpp>
#include <vector>

/// @brief обёртка над sfml-евским sound/soundbuffer
///        по сути - массив Sound
class SFMLSound {
protected:
    std::vector<sf::Sound> sound;
public:
    SFMLSound() {}
    SFMLSound(std::vector<sf::Sound> && s) {
        sound = s;
        s.clear();
    }
    SFMLSound(const std::vector<std::shared_ptr<sf::SoundBuffer>> & sound_buffers) {
        for (auto & sb : sound_buffers) {
            sound.push_back(sf::Sound());
            sound.front().setBuffer(*sb);
            sound.front().setVolume(100);
        }
    }

    void play(size_t i=0) {
        if (i >= sound.size())
            throw std::invalid_argument("too big index for sound vector");

        sound[i].play();
    }
    void stop(size_t i=0) {
        if (i >= sound.size())
            throw std::invalid_argument("too big index for sound vector");

        sound[i].stop();
    }
    void pause(size_t i=0) {
        if (i >= sound.size())
            throw std::invalid_argument("too big index for sound vector");
        
        sound[i].pause();
    }

    const sf::Sound & get_sound(size_t i) const {
        if (i >= sound.size())
            throw std::invalid_argument("too big index for sound vector");
        
        return sound[i];
    }
    std::vector <sf::Sound> & get_sounds()
    { return sound; }
};

#endif