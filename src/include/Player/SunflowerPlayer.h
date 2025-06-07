//
// Created by gaksy on 2025/6/6.
//

#ifndef SUNFLOWERPLAYER_H
#define SUNFLOWERPLAYER_H
#include "Player.h"


class SunflowerPlayer: public Player{
public:
    SunflowerPlayer();
    ~SunflowerPlayer() override = default;

public:
    void onUpdate(size_t delta)override;
    void onDraw(const Camera& camera) override;
    void onInput(const sf::Event& event) override;

private:

};



#endif //SUNFLOWERPLAYER_H
