#include "../include/ResourcesUnit/Animation.h"

#include <utility>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

void Animation::reset() {
    timer_ = 0;
    index_frame_ = 0;
}

void Animation::setAtlas(Atlas* atlas) {
    atlas_ = atlas;
}

void Animation::setLoop(const bool loop) {
    is_loop_ = loop;
}

void Animation::setInterval(const size_t ms) {
    interval_ = ms;
}

void Animation::setCallBack(std::function<void()> callback) {
    this->callback_ = std::move(callback);
}

size_t Animation::getIndexFrame() const {
    return index_frame_;
}

const sf::Texture* Animation::getCurrentFrame() const {
    return atlas_->getFrameImage(index_frame_);
}

bool Animation::checkFinished() const {
    if (is_loop_) { return false; }
    return (index_frame_ == atlas_->getFrameImageSize() - 1);
}

void Animation::onUpdate(const size_t delta)
{
    timer_ += delta;
    if (timer_ >= interval_) {
        timer_ = 0;
        index_frame_++;
        if (index_frame_ >= atlas_->getFrameImageSize()) {
            index_frame_ = is_loop_ ? 0 : atlas_->getFrameImageSize() - 1;
            if (!is_loop_ && callback_) {
                callback_();
            }
        }
    }
}

void Animation::onDraw(const float x, const float y) const
{
    sf::RectangleShape rectangle_shape(sf::Vector2f(x, y));
    rectangle_shape.setTexture(atlas_->getFrameImage(index_frame_));
    p_window_->draw(rectangle_shape);
}
