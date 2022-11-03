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
    world.add_things_from_file(static_path / containers);
    world.add_npcs_from_file(static_path / npc_file);
    world.add_effects_from_file(static_path / effect_file);
    world.add_character(static_path / hero_file);


    while (window.isOpen()) {
        Map map(world);
        // проверить все события окна, которые были вызваны с последней итерации цикла
        sf::Event event;
        if (window.pollEvent(event)) {
            // "запрос закрытия" событие: мы закрываем окно
            if (event.type == sf::Event::Closed)
                window.close();

            // обработываем полученное действие и движения всех объектов
            world.interraction(event, window);
            
            if (event.type == sf::Event::Resized) {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(sf::Vector2f(0.f, 0.f), sf::Vector2f((float)event.size.width, (float)event.size.height));
                window.setView(sf::View(visibleArea));
            }
        }


        // очищаем окно и заливаем черным цветом
        window.clear(sf::Color::Black);

        // создаём карту объектов, которые видны герою
        // map = Map(world);

        // std::cout << "hero position: (" << map.get_hero().get_sprite().getPosition().x << ", " << map.get_hero().get_position().second << ")\n";

        // отрисовываем карту
        Draw::draw_map(window, map);

        // конец текущего кадра - отображаем
        window.display();

        // int a = 0;
        // std::cin >> a;
        world.iterate();
    }

    return 0;
}