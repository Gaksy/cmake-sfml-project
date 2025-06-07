#include "Player/SunflowerPlayer.h"

#include <SFML/Graphics/RenderWindow.hpp>

SunflowerPlayer::SunflowerPlayer()
{ }

void SunflowerPlayer::onUpdate(size_t delta)
{
    printf("SunflowerPlayer::onUpdate()\n");
}

void SunflowerPlayer::onDraw(const Camera& camera, sf::RenderWindow& window)
{

}

void SunflowerPlayer::onInput(const sf::Event& event)
{
    Player::onInput(event);
}
