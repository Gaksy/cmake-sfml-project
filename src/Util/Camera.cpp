#include "Util/Camera.h"

#include <SFML/Window/Mouse.hpp>

Camera::Camera():
    position_({0,0}),
    is_shaking_(false),
    shaking_strength_(0)
{
    timer_shake_.setOneShot(true);
    timer_shake_.setCallback([&]() {
        is_shaking_ = false;
        resetPosition();
    });
}

const sf::Vector2f& Camera::getPosition() const{
    return position_;
}

void Camera::setPosition(const sf::Vector2f& position){
    position_ = position;
}

void Camera::resetPosition() {
    position_ = sf::Vector2f(0,0);
}

void Camera::onUpdate(const size_t delta){
    timer_shake_.onUpdate(delta);

    if (is_shaking_) {
        position_.x = (-50 + rand() % 100) / 50.0f * shaking_strength_;
        position_.y = (-50 + rand() % 100) / 50.0f * shaking_strength_;
    }
}

void Camera::shake(const float strength, const size_t duration) {
    is_shaking_ = true;
    shaking_strength_ = strength;

    timer_shake_.setWaitTime(duration);
    timer_shake_.restart();
}

