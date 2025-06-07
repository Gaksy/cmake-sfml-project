#include "PeashooterPlayer.h"

PeashooterPlayer::PeashooterPlayer()
{
}

void PeashooterPlayer::onUpdate(size_t delta)
{
    printf("PeashooterPlayer::onUpdate()\n");
}

void PeashooterPlayer::onDraw(const Camera& camera)
{
    Player::onDraw(camera);
}

void PeashooterPlayer::onInput(const sf::Event& event)
{
    Player::onInput(event);
}
