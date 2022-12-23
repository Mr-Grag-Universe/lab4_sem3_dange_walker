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


#include "../Map.hpp"
#include "../draw/Draw.hpp"
#include "message.hpp"
#include "sfml_message_window.hpp"


void message(sf::RenderWindow & window, World & world) {
    Map map(world);

    std::shared_ptr<sf::Texture> field_texture = std::make_shared<sf::Texture>();
    if (!field_texture->loadFromFile(mp::img / fs::path("message_field.jpg"))) {
        throw std::runtime_error("we cannot load message background texture");
    }

    SFML_Message message = SFML_Message(world.get_messages().front());
    message.set_label_size(std::make_pair(world.get_W()/4, world.get_H()/4));
    message.set_position(std::make_pair(world.get_W()/2, world.get_H()/2));
    message.set_text_size(24);
    message.set_field_color(sf::Color::Cyan);
    message.set_field_texture(field_texture);
    message.set_text_color(sf::Color::Green);

    while (window.isOpen() && world.get_game_mode() == World::MESSAGE) {
        // проверить все события окна, которые были вызваны с последней итерации цикла
        sf::Event event;
        if (window.pollEvent(event)) {
            // "запрос закрытия" событие: мы закрываем окно
            if (event.type == sf::Event::Closed)
                window.close();

            // обработываем полученное действие и движения всех объектов
            world.interraction(event, window);

            // update message
            message.set_text(world.get_messages().front());
            
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

        // отрисовываем карту
        Draw::draw_map(window, map);
        message.draw(window);

        // конец текущего кадра - отображаем
        window.display();
    }
    world.set_GameOver();
}