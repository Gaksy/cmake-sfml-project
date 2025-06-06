#include "Scene/GameScene.h"

#include <cstdio>

#include "Scene/SceneManager.h"

extern SceneManager game_scene_manager;

GameScene::GameScene(const sf::Font& font, sf::RenderWindow* p_window):
    Scene(font, p_window, L"游戏局内场景")
{ ; }

GameScene::GameScene(sf::RenderWindow* p_window):
    Scene(p_window, L"游戏局内场景")
{ ; }

GameScene::~GameScene() {
    Scene::~Scene();
}

void GameScene::onEnter() {
    printf("进入游戏局内场景\n");
}

void GameScene::onExit() {
    printf("退出游戏局内场景\n");
}

void GameScene::onUpdate(const size_t delta) {

}

void GameScene::onDraw(const Camera& camera) {

}

void GameScene::onInput(const sf::Event& event) {
    if (event.is<sf::Event::KeyPressed>()) {
        game_scene_manager.switchToScene(SceneManager::SceneType::MENU);
    }
}
