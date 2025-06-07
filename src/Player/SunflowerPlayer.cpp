#include "Player/SunflowerPlayer.h"

#include <SFML/Graphics/RenderWindow.hpp>

extern Atlas atlas_sunflower_idle_left;        // 龙日葵朝向左的默认动画图集
extern Atlas atlas_sunflower_idle_right;       // 龙日葵朝向右的默认动画图集
extern Atlas atlas_sunflower_run_left;         // 龙日葵朝向左的跑步动画图集
extern Atlas atlas_sunflower_run_right;        // 龙日葵朝向右的跑步动画图集

SunflowerPlayer::SunflowerPlayer() {
    animation_idel_left_.setAtlas(&atlas_sunflower_idle_left);
    animation_idel_right_.setAtlas(&atlas_sunflower_idle_right);
    animation_run_left_.setAtlas(&atlas_sunflower_run_left);
    animation_run_right_.setAtlas(&atlas_sunflower_run_right);

    animation_idel_left_.setInterval(75);
    animation_idel_right_.setInterval(75);
    animation_run_left_.setInterval(75);
    animation_run_right_.setInterval(75);
}

void SunflowerPlayer::onUpdate(size_t delta)
{
    Player::onUpdate(delta);
}

void SunflowerPlayer::onDraw(const Camera& camera)
{
    Player::onDraw(camera);
}

void SunflowerPlayer::onInput(const sf::Event& event)
{
    Player::onInput(event);
}
