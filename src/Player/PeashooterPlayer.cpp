#include "Player/PeashooterPlayer.h"

#include <SFML/Graphics/RenderWindow.hpp>

PeashooterPlayer::PeashooterPlayer()
{
}

void PeashooterPlayer::onUpdate(size_t delta)
{
    printf("PeashooterPlayer::onUpdate()\n");
}

void PeashooterPlayer::onDraw(const Camera& camera, sf::RenderWindow& window)
{

}

void PeashooterPlayer::onInput(const sf::Event& event)
{
    Player::onInput(event);
}
