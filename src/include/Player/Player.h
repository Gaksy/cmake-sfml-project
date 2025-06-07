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
    void setPosition(sf::Vector2f pos);
    void onRun(float distance);
    void onJump();

protected:
        void moveAndCollide(int delta);

protected:
    Animation animation_idel_left_;
    Animation animation_idel_right_;
    Animation animation_run_left_;
    Animation animation_run_right_;

    sf::Vector2f position_;         // 位置
    sf::Vector2f velocity_;         // 加速度
    sf::Vector2f player_size_;      // 玩家大小

    const float run_velocity_;
    const float gravity_;       // 重力加速度
    const float jump_velocity_;

private:
    Animation* p_currnet_animation_;

    PlayerID player_id_;

    bool is_left_key_down_;
    bool is_right_key_down_;

    bool is_facing_right_;
};

#endif //PLAYER_H
