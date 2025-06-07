#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Util/Camera.h"

class Player {
public:
    Player()=default;
    virtual  ~Player()=default;

public:
    virtual void onUpdate(size_t delta);
    virtual void onDraw(const Camera& camera, sf::RenderWindow& window);
    virtual void onInput(const sf::Event& event);

private:

};

#endif //PLAYER_H
