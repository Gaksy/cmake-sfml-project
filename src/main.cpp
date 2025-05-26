#include <SFML/Graphics.hpp>

#include "Scene/MenuScene.h"
#include "Scene/Scene.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920u, 1080u}), "Test", sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Color backgroundColor = sf::Color::White;
    sf::Font font("resources/font_file/NISC18030.ttf");
    Scene* p_scene = new MenuScene(font, &window) ;


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) { window.close(); }
            if (event) {
                p_scene->onInput(*event);
            }
        }

        p_scene->update();

        window.clear(backgroundColor);
        p_scene->onDraw();
        window.display();
    }
}
