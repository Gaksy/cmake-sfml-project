#include "Scene/SelectorScene.h"

SelectorScene::SelectorScene(const sf::Font& font, sf::RenderWindow* p_window):
    Scene(font, p_window, L"选角场景")
{
}

void SelectorScene::onEnter() {
    printf("进入选角场景\n");
}

void SelectorScene::onExit()
{
    printf("退出选角场景\n");
}

void SelectorScene::onUpdate()
{
    printf("正在运行选角场景\n");
}

void SelectorScene::onDraw()
{
    drawSceneLabel();
}

void SelectorScene::onInput(const sf::Event& event)
{
    ;
}
