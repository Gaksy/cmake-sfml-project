#include "Scene/MenuScene.h"

#include <cstdio>

#include "Scene/SceneManager.h"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Sleep.hpp"

extern SceneManager game_scene_manager;
extern sf::Texture img_menu_background;
extern sf::SoundBuffer sound_bgm_menu;
extern sf::SoundBuffer sound_ui_confirm;

MenuScene::MenuScene(const sf::Font& font, sf::RenderWindow* p_window):
    Scene(font, p_window, L"菜单场景"),
    animation_peashooter_run_right_(p_window),
    p_sound_background_bgm_(nullptr),
    p_sound_ui_confirm_(nullptr)
{

}

void MenuScene::onEnter() {
    resetSound(p_sound_background_bgm_, sound_bgm_menu, true, true);
    resetSound(p_sound_ui_confirm_, sound_ui_confirm);
}

void MenuScene::onExit() {
    freeSound(p_sound_background_bgm_);
    freeSound(p_sound_ui_confirm_, true);
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
        p_sound_ui_confirm_->play();
        game_scene_manager.switchToScene(SceneManager::SceneType::SELECTOR);
    }
}
