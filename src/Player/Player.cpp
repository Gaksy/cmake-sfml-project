#include "Player/Player.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "../../cmake-build-debug/_deps/sfml-src/extlibs/headers/stb_image/stb_image_write.h"

Player::Player():
    position_({0,0}),
    player_id_(PlayerID::P1),
    is_left_key_down_(false),
    is_right_key_down_(false),
    is_facing_right(true),
    p_currnet_animation_(&animation_idel_right_)
{ ; }

void Player::setPlayerID(const PlayerID player_id) {
    player_id_ = player_id;
}

void Player::onUpdate(size_t delta)
{
    int direction = is_right_key_down_ - is_left_key_down_;
    if(direction!=0) {
        is_facing_right = direction > 0;
        p_currnet_animation_ = is_facing_right ? &animation_run_right_ : & animation_idel_left_;
    }
    else {
        p_currnet_animation_ = is_facing_right ? &animation_idel_right_ : &animation_idel_left_;
    }

    p_currnet_animation_->onUpdate(delta);
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
                switch (event.getIf<sf::Event::KeyPressed>()->code) {
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
