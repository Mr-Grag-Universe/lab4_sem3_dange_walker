#include <string>
#include <iostream>
// GLFW
// #include <GLFW/glfw3.h>
// #include <GLFW/glfw3native.h>
// #include <glad/gl.h>
// SFML
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "all_headers.hpp"
#include "game.hpp"
#include "menu.hpp"
#include "backpack_menu.hpp"


int main(int argc, char *argv[]) {
    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    std::cout << "desktop: (" << mode.size.x << "; " << mode.size.y << ")\n";
    sf::Vector2u size((int) mode.size.x, (int) mode.size.y);
    // sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WIDTH, HEIGHT)), "Walker Game");
    sf::RenderWindow window(sf::VideoMode(size), "Walker Game");

    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    // std::vector <std::unique_ptr<Obj>> things = World::load_things_from_file("/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/static/first_room.txt");
    // std::cout << static_path;
    World world(static_path / first_room);
    world.add_game_obj_textures_from_file(static_path / game_obj_file);
    world.add_things_from_file(static_path / containers);
    world.add_npcs_from_file(static_path / npc_file);
    world.add_effects_from_file(static_path / effect_file);
    world.add_character(static_path / hero_file);

    window.clear(sf::Color::Black);
    // std::shared_ptr<sf::Texture> texture = (world.get_effect_texture(MW_WAVE)).textures[0];
    // sf::Vector2 position_in((int) 0, (int) 0);
    std::pair <unsigned int, unsigned int> scale(100, 100);
    fs::path file_path("weapon_effects_sprites/Big_Preview.png");
    sf::Vector2 size_f((float) (scale.first), (float) (scale.second));
    sf::Vector2 size_i((int) (scale.first), (int) (scale.second));
    sf::Vector2 size_r((int) (scale.first), (int) (scale.second));
    // if (!texture->loadFromFile(static_path / file_path, sf::IntRect(position_in, size_i))) {
    //     std::cout << "cannot read texture from file : " << file_path << std::endl;
    //    throw std::invalid_argument("there is not such file with texture");
    //}

    // sf::Sprite sprite;
    // sprite.setTexture(*texture);
    // sf::Vector2 p_v((float) 1910/2, (float) 1080/2);
    // sprite.setPosition(p_v);
    // window.draw(sprite);
    // window.display();
    // window.draw(sprite);

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