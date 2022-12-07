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
#include <thread>
#include <queue>

#include "../all_headers.hpp"
#include "game.hpp"

std::mutex mutex;

void events_catcher(World & world, std::queue <sf::Event> & events, sf::RenderWindow & window) {
    sf::Event event;
    while (window.isOpen() && world.get_game_mode() == World::RUN) {
        mutex.lock();
        if (window.pollEvent(event)) {
            events.emplace(event);
        }
        mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));   //Можно убрать, если хотите  (сделано для уменьшения нагрузки на проц)
    }
}

void interract_thread_func(World & world, sf::Event & event, sf::RenderWindow & window) {
    // std::thread pr(func, std::ref(world), std::ref(event), std::ref(window));
    while (window.isOpen() && world.get_game_mode() == World::RUN) {
        if (window.pollEvent(event)) {
            // "запрос закрытия" событие: мы закрываем окно
            if (event.type == sf::Event::Closed)
                window.close();

            // обработываем полученное действие и движения всех объектов
            // world.interraction(event, window);
            
            if (event.type == sf::Event::Resized) {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(sf::Vector2f(0.f, 0.f), sf::Vector2f((float)event.size.width, (float)event.size.height));
                window.setView(sf::View(visibleArea));
            }
        }
    }
}

void game(sf::RenderWindow & window, World & world) {
    Map map(world);
    Draw::draw_map(window, map);
    // sf::Event event;
    std::queue <sf::Event> events;
    std::thread pr1(events_catcher, std::ref(world), std::ref(events), std::ref(window));
    std::thread pr2(events_catcher, std::ref(world), std::ref(events), std::ref(window));
    std::thread pr3(events_catcher, std::ref(world), std::ref(events), std::ref(window));
    while (window.isOpen() && world.get_game_mode() == World::RUN) {
        // Map map(world);
        map.update();
        while(!events.empty()) {
            // проверить все события окна, которые были вызваны с последней итерации цикла
            // if (window.pollEvent(event)) {
                // "запрос закрытия" событие: мы закрываем окно
                sf::Event &event = events.front();
                if (event.type == sf::Event::Closed)
                    window.close();
                world.interraction(event, window);
                if (event.type == sf::Event::Resized) {
                    // update the view to the new size of the window
                    sf::FloatRect visibleArea(sf::Vector2f(0.f, 0.f), sf::Vector2f((float)event.size.width, (float)event.size.height));
                    window.setView(sf::View(visibleArea));
                }
                mutex.lock();
                events.pop();
                mutex.unlock();
                // обработываем полученное действие и движения всех объектов
                
            // }
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

    pr1.detach();
    pr2.detach();
    pr3.detach();
}