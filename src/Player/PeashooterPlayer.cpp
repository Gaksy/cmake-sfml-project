#include "Player/PeashooterPlayer.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "../../cmake-build-debug/_deps/sfml-src/extlibs/headers/stb_image/stb_image_write.h"

extern Atlas atlas_peashooter_idle_left;       // 婉逗射手朝向左的默认动画图集
extern Atlas atlas_peashooter_idle_right;      // 婉逗射手朝向右的默认动画图集
extern Atlas atlas_peashooter_run_left;        // 婉逗射手朝向左的跑步动画图集
extern Atlas atlas_peashooter_run_right;       // 婉逗射手朝向右的跑步动画图集

PeashooterPlayer::PeashooterPlayer()
{
    animation_idel_left_.setAtlas(&atlas_peashooter_idle_left);
    animation_idel_right_.setAtlas(&atlas_peashooter_idle_right);
    animation_run_left_.setAtlas(&atlas_peashooter_run_left);
    animation_run_right_.setAtlas(&atlas_peashooter_run_right);

    animation_idel_left_.setInterval(75);
    animation_idel_right_.setInterval(75);
    animation_run_left_.setInterval(75);
    animation_run_right_.setInterval(75);
}

void PeashooterPlayer::onUpdate(size_t delta)
{
    Player::onUpdate(delta);
}

void PeashooterPlayer::onDraw(const Camera& camera)
{
    Player::onDraw(camera);
}

void PeashooterPlayer::onInput(const sf::Event& event)
{
    Player::onInput(event);
}
