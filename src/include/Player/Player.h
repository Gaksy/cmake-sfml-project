#ifndef PLAYER_H
#define PLAYER_H

#include <ResourcesUnit/Animation.h>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "Util/Camera.h"
#include "Player/PlayerID.h"

class Player {
public:
    Player();
    virtual  ~Player()=default;

public:
    virtual void onUpdate(size_t delta);
    virtual void onDraw(const Camera& camera);
    virtual void onInput(const sf::Event& event);
    void setPlayerID(PlayerID player_id);

private:
    sf::Vector2f position_;

    Animation animation_idel_left_;
    Animation animation_idel_right_;
    Animation animation_run_left_;
    Animation animation_run_right_;

    Animation* p_currnet_animation_;

    PlayerID player_id_;

    bool is_left_key_down_;
    bool is_right_key_down_;

    bool is_facing_right;
};

#endif //PLAYER_H
