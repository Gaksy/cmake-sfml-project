#include "include/Scene/MenuScene.h"

#include <cstdio>

#include "SFML/Graphics/Text.hpp"

MenuScene::MenuScene(const sf::Font& font, sf::RenderWindow* p_window):
    Scene(font, p_window, L"菜单场景")
{ }

void MenuScene::onEnter()
{
    printf("进入主菜单场景\n");
}

void MenuScene::onExit()
{
    printf("退出主菜单场景\n");
}

void MenuScene::update()
{
    printf("正在运行主菜单场景...\n");
}

void MenuScene::onDraw()
{
    drawSceneLabel();
}

void MenuScene::onInput(const sf::Event& event)
{
}
