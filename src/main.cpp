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

#include "draw/Draw.hpp"
#include "World.hpp"
#include "Map.hpp"

int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WIDTH, HEIGHT)), "Walker Game");

    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);


    std::vector <std::unique_ptr<Obj>> things = World::load_things_from_file("/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/static/first_room.txt");
    World world("/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/static/first_room.txt");
    Map map;

    while (window.isOpen()) {
        // проверить все события окна, которые были вызваны с последней итерации цикла
        sf::Event event;
        while (window.pollEvent(event)) {
            // "запрос закрытия" событие: мы закрываем окно
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // очищаем окно и заливаем черным цветом
        window.clear(sf::Color::Black);

        // обработываем полученное действие и движения всех объектов
        world.interraction(event);
        // создаём карту объектов, которые видны герою
        map = world.create_map();

        // отрисовываем карту
        Draw::draw_map(window, map);

        // рисуем что-нибудь здесь
        // window.draw(...);

        // конец текущего кадра - отображаем
        window.display();
    }

    return 0;
}