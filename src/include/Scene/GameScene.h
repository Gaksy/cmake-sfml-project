#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Scene.h"

class GameScene : public Scene
{
public:
    explicit GameScene(const sf::Font& font);
    explicit GameScene();
    ~GameScene() override;

public:
    void onEnter()override;
    void onExit()override;
    void onUpdate(size_t delta)override;
    void onDraw(const Camera& camera)override;
    void onInput(const sf::Event& event)override;

private:
    sf::Vector2f pos_img_sky_;
    sf::Vector2f pos_img_hills_;
};


#endif //GAMESCENE_H
