#include "Scene/MenuScene.h"

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "ResourcesUnit/SoundManager.h"
#include "Scene/SceneManager.h"


extern SceneManager game_scene_manager;
extern sf::Texture img_menu_background;
extern SoundManager game_sound_manager;

MenuScene::MenuScene(const sf::Font& font, sf::RenderWindow* p_window):
    Scene(font, p_window, L"菜单场景"),
    animation_peashooter_run_right_(p_window)
{ ; }

void MenuScene::onEnter() {
    game_sound_manager.setSoundLoop("bgm_menu", true);
    game_sound_manager.playSound("bgm_menu");
}

void MenuScene::onExit() {
    game_sound_manager.stopSound("bgm_menu");
}

void MenuScene::onUpdate(const size_t delta) {

}

void MenuScene::onDraw(const Camera& camera) {
    sf::RectangleShape background;
    background.setPosition({0,0});
    background.setTexture(&img_menu_background);
    background.setSize(sf::Vector2f(img_menu_background.getSize()));

    getWindow().draw(background);
}

void MenuScene::onInput(const sf::Event& event) {
    if (event.is<sf::Event::KeyPressed>()){
        game_sound_manager.playSound("ui_confirm");
        game_scene_manager.switchToScene(SceneManager::SceneType::SELECTOR);
    }
}
