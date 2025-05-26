//
// Created by gaksy on 2025/5/25.
//

#ifndef MENUSCENE_H
#define MENUSCENE_H
#include "Scene.h"


class MenuScene: public Scene{
public:
    MenuScene(const sf::Font& font, sf::RenderWindow* p_window);
    ~MenuScene() override=default;

public:
    void onEnter()override;
    void onExit()override;
    void update()override;
    void onDraw()override;
    void onInput(const sf::Event& event)override;
};



#endif //MENUSCENE_H
