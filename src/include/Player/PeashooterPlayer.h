#ifndef PEASHOTTERPLAYER_H
#define PEASHOTTERPLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Player/Player.h"

class PeashooterPlayer: public Player {
public:
    PeashooterPlayer();
    ~PeashooterPlayer() override = default;

    void onUpdate(size_t delta)override;
    void onDraw(const Camera& camera, sf::RenderWindow& window) override;
    void onInput(const sf::Event& event) override;

private:

};

#endif //PEASHOTTERPLAYER_H
