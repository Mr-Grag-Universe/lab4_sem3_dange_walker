#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "all_headers.hpp"
#include "game.hpp"
#include "menu.hpp"
#include "backpack_menu.hpp"
#include "boot_menu.hpp"


int main(int argc, char *argv[]) {
    Settings settings;
    if (!boot_menu(settings))
        return 0;

    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    std::cout << "desktop: (" << mode.size.x << "; " << mode.size.y << ")\n";
    sf::Vector2u size((int) mode.size.x, (int) mode.size.y);
    // sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WIDTH, HEIGHT)), "Walker Game");
    sf::RenderWindow window(sf::VideoMode(size), "Walker Game");

    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    World world(mp::logs / mp::first_room);
    world.add_game_obj_textures_from_file(mp::logs / mp::game_obj_file);
    world.add_things_from_file(mp::logs / mp::containers);
    world.add_npcs_from_file(mp::logs / mp::npc_file);
    world.add_character(mp::logs / mp::hero_file);

    window.clear(sf::Color::Black);

    sf::Music my_sound;
    if (!my_sound.openFromFile(mp::sound / "neheart_Reidenshi_-_snowfall_73879469.mp3")) {
        std::cout << "cannot open music file" << std::endl;
        return 1;
    }
    my_sound.play();
    my_sound.setVolume(10);

    while (window.isOpen()) {
        switch (world.get_game_mode())
        {
        case World::RUN:
            game(window, world);
            break;
        case World::MENU:
            menu(window, world);
            break;
        case World::BACKPACK_MENU:
            backpack_menu(window, world);
            break;
        default:
            break;
        }
    }

    return 0;
}