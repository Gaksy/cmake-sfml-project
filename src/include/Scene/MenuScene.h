#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Scene/Scene.h"
#include "ResourcesUnit/Animation.h"
#include "Util/Camera.h"
#include "Util/Timer.h"

class MenuScene: public Scene{
public:
    explicit MenuScene(const sf::Font& font);
    explicit MenuScene();
    ~MenuScene() override=default;

public:
    void onEnter()override;
    void onExit()override;
    void onUpdate(size_t delta)override;
    void onDraw(const Camera& camera)override;
    void onInput(const sf::Event& event)override;

private:
    Animation animation_peashooter_run_right_;
    Camera camera;
    Timer timer;
};



#endif //MENUSCENE_H
