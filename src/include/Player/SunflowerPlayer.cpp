#include "SunflowerPlayer.h"

SunflowerPlayer::SunflowerPlayer()
{ }

void SunflowerPlayer::onUpdate(size_t delta)
{
    printf("SunflowerPlayer::onUpdate()\n");
}

void SunflowerPlayer::onDraw(const Camera& camera)
{
    Player::onDraw(camera);
}

void SunflowerPlayer::onInput(const sf::Event& event)
{
    Player::onInput(event);
}
