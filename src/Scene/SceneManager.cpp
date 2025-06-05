#include "Scene/SceneManager.h"

extern Scene* p_menu_scene;
extern Scene* p_selector_scene;
extern Scene* p_game_scene;

SceneManager::SceneManager():
    p_current_scene_(nullptr)
{
}

void SceneManager::setCurrentScene(Scene* p_scene) {
    p_current_scene_ = p_scene;
    p_scene->onEnter();
}

void SceneManager::switchToScene(SceneType sceneType)
{
    p_current_scene_->onExit();
    switch(sceneType)
    {
    case SceneType::MENU:
        p_current_scene_ = p_menu_scene;
        break;
    case SceneType::SELECTOR:
        p_current_scene_ = p_selector_scene;
        break;
    case SceneType::GAME:
        p_current_scene_ = p_game_scene;
        break;
    default:
        break;
    }
    p_current_scene_->onEnter();
}

void SceneManager::onUpdate(const size_t delta) const
{
    p_current_scene_->onUpdate(delta);
}

void SceneManager::onDraw(const Camera& camera) const
{
    p_current_scene_->onDraw(camera);
    p_current_scene_->drawSceneLabel();
}

void SceneManager::onInput(const sf::Event& event) const
{
    p_current_scene_->onInput(event);
}
