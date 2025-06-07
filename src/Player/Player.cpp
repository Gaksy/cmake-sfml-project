#include "Player/Player.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <Util/Platform.h>

extern std::vector<Platform> platform_list;

Player::Player():
    position_({0,0}),
    player_id_(PlayerID::P1),
    is_left_key_down_(false),
    is_right_key_down_(false),
    is_facing_right_(true),
    p_currnet_animation_(&animation_idel_right_),
    run_velocity_(0.55f),
    gravity_(1.6e-3f),
    player_size_({96, 96}),
    jump_velocity_(-0.85f)
{ ; }

void Player::setPlayerID(const PlayerID player_id) {
    player_id_ = player_id;
}

void Player::setPosition(const sf::Vector2f pos) {
    position_ = pos;
}

void Player::onRun(const float distance) {


    position_.x += distance;

}

void Player::onJump() {
    if(velocity_.y != 0) return;


    for(const Platform& platform: platform_list) {
        const Platform::CollisionShape& shape = platform.getShape();
        bool is_collide_x = (
            std::max(position_.x + player_size_.x, shape.right) -
            std::min(position_.x, shape.left)
        ) <= player_size_.x + (shape.right - shape.left);
        bool is_collide_y = (
            shape.y >= position_.y && shape.y <= position_.y + player_size_.y
        );

        if(is_collide_x && is_collide_y) {
            velocity_.y += jump_velocity_;
            break;
        }
    }
}

void Player::moveAndCollide(int delta) {
    delta = 16;
    velocity_.y += gravity_ * static_cast<float>(delta);

    if (velocity_.y > 0) {
        velocity_.y = std::min(velocity_.y, 0.8f);
    }
    else if(velocity_.y < 0) {
        velocity_.y = std::max(velocity_.y, -0.9f);
    }

    position_ += velocity_ * static_cast<float>(delta);

    if(player_id_ == PlayerID::P2 && velocity_.y < 1) {
        printf("P2: %f %d\n", velocity_.y, delta);
    }

    if(velocity_.y > 0) {
        for(const Platform& platform: platform_list) {
            const Platform::CollisionShape& shape = platform.getShape();
            bool is_collide_x = (
                std::max(position_.x + player_size_.x, shape.right) -
                std::min(position_.x, shape.left)
            ) <= player_size_.x + (shape.right - shape.left);
            bool is_collide_y = (
                shape.y >= position_.y && shape.y <= position_.y + player_size_.y
            );

            if(is_collide_x && is_collide_y) {
                float delta_pos_y = velocity_.y * static_cast<float>(delta);
                float last_tick_foot_pos_y = position_.y + player_size_.y - delta_pos_y;
                if (last_tick_foot_pos_y <= shape.y) {
                    position_.y = shape.y - player_size_.y;
                    velocity_.y = 0;
                    break;
                }
            }
        }
    }
}

void Player::onUpdate(const size_t delta)
{
    int direction = is_right_key_down_ - is_left_key_down_;
    if(direction!=0) {
        is_facing_right_ = direction > 0;
        p_currnet_animation_ = is_facing_right_ ? &animation_run_right_ : & animation_idel_left_;
        float distance = direction * run_velocity_ * delta;
        onRun(distance);
    }
    else {
        p_currnet_animation_ = is_facing_right_ ? &animation_idel_right_ : &animation_idel_left_;
    }

    p_currnet_animation_->onUpdate(delta);

    moveAndCollide(delta);
}

void Player::onDraw(const Camera& camera)
{
    p_currnet_animation_->onDraw(camera, position_.x, position_.y);
}

void Player::onInput(const sf::Event& event)
{
    if(event.is<sf::Event::KeyPressed>()) {
        switch (player_id_) {
            case PlayerID::P1:
                switch (event.getIf<sf::Event::KeyPressed>()->code) {
                    case sf::Keyboard::Key::A:
                        is_left_key_down_ = true;
                    break;
                    case sf::Keyboard::Key::D:
                        is_right_key_down_ = true;
                    break;
                    case sf::Keyboard::Key::W:
                        onJump();
                    break;
                    default:
                        break;
                }
            break;
            case PlayerID::P2:
                switch (event.getIf<sf::Event::KeyPressed>()->code) {
                    case sf::Keyboard::Key::Left:
                        is_left_key_down_ = true;
                    break;
                    case sf::Keyboard::Key::Right:
                        is_right_key_down_ = true;
                    break;
                    case sf::Keyboard::Key::Up:
                        onJump();
                    break;
                    default:
                        break;
                }
            break;
            default:
                break;
        }
    }
    if(event.is<sf::Event::KeyReleased>()) {
        switch (player_id_) {
            case PlayerID::P1:
                switch (event.getIf<sf::Event::KeyReleased>()->code) {
                    case sf::Keyboard::Key::A:
                        is_left_key_down_ = false;
                    break;
                    case sf::Keyboard::Key::D:
                        is_right_key_down_ = false;
                    break;
                    default:
                        break;
                }
            break;
            case PlayerID::P2:
                switch (event.getIf<sf::Event::KeyReleased>()->code) {
                    case sf::Keyboard::Key::Left:
                        is_left_key_down_ = false;
                    break;
                    case sf::Keyboard::Key::Right:
                        is_right_key_down_ = false;
                    break;
                    default:
                        break;
                }
            break;
            default:
                break;
        }
    }
}
