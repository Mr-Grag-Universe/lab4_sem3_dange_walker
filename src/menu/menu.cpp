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

#include "../all_headers.hpp"


void menu(sf::RenderWindow & window, World & world) {
    while (window.isOpen() && world.get_game_mode() == World::MENU) {
        // Map map(world);
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
        window.clear(sf::Color::Cyan);

        // создаём карту объектов, которые видны герою
        // map = Map(world);

        // отрисовываем карту
        // Draw::draw_map(window, map);

        // конец текущего кадра - отображаем
        window.display();
    }
}