#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <SFML/Window/Event.hpp>

#include "Scene/Scene.h"

class SceneManager {
public:
    enum class SceneType
    {
        MENU,
        SELECTOR,
        GAME
    };
public:
    SceneManager();
    ~SceneManager()=default;

    void setCurrentScene(Scene* p_scene);
    void switchToScene(SceneType sceneType);

    void onUpdate(size_t delta) const;
    void onDraw(const Camera& camera) const;
    void onInput(const sf::Event& event) const;

private:
    Scene* p_current_scene_ = nullptr;
};



#endif //SCENEMANAGER_H
