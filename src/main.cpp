#include <SFML/Graphics.hpp>

#include "Scene/GameScene.h"
#include "Scene/MenuScene.h"
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"
#include "Scene/SelectorScene.h"

Scene* p_menu_scene = nullptr;
Scene* p_game_scene = nullptr;
Scene* p_selector_scene = nullptr;

SceneManager game_scene_manager;

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920u, 1080u}), "Test", sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Color backgroundColor = sf::Color::White;
    sf::Font font("resources/font_file/NISC18030.ttf");
    p_menu_scene = new MenuScene(font, &window);
    p_selector_scene = new SelectorScene(font, &window);
    p_game_scene = new GameScene(font, &window);

    game_scene_manager.setCurrentScene(p_menu_scene);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) { window.close(); }
            if (event) {
                game_scene_manager.onInput(*event);
            }
        }

        game_scene_manager.onUpdate();

        window.clear(backgroundColor);
        game_scene_manager.onDraw();
        window.display();
    }

    delete p_menu_scene;
    delete p_game_scene;
}
