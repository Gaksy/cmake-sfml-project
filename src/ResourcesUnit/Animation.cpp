#include "../include/ResourcesUnit/Animation.h"

#include <utility>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Util/Camera.h"

extern sf::RenderWindow window;

Animation::Animation():
    timer_(0),
    index_frame_(0),
    is_loop_(true),
    interval_(0),
    p_window_(&window),
    p_atlas_(nullptr)
{ ; }

void Animation::reset() {
    timer_ = 0;
    index_frame_ = 0;
}

void Animation::setAtlas(Atlas* atlas) {
    p_atlas_ = atlas;
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
    return p_atlas_->getFrameImage(index_frame_);
}

bool Animation::checkFinished() const {
    if (is_loop_) { return false; }
    return (index_frame_ == p_atlas_->getFrameImageSize() - 1);
}

void Animation::onUpdate(const size_t delta)
{
    timer_ += delta;
    if (timer_ >= interval_) {
        timer_ = 0;
        index_frame_++;
        if (index_frame_ >= p_atlas_->getFrameImageSize()) {
            index_frame_ = is_loop_ ? 0 : p_atlas_->getFrameImageSize() - 1;
            if (!is_loop_ && callback_) {
                callback_();
            }
        }
    }
}

void Animation::onDraw(const Camera& camera, const float x, const float y) const
{
    if (p_window_)
        onDraw(x - camera.getPosition().x, y - camera.getPosition().y);
}

void Animation::onDraw(float x, float y) const
{
    if (!p_window_) return;
    const sf::Texture* texture = p_atlas_->getFrameImage(index_frame_);

    if (texture != nullptr) {
        const sf::Vector2u texture_size = texture->getSize();
        sf::RectangleShape rectangle_shape(
            sf::Vector2f(static_cast<float>(texture_size.x), static_cast<float>(texture_size.y))
        );

        rectangle_shape.setPosition({x, y});
        rectangle_shape.setTexture(texture);
        p_window_->draw(rectangle_shape);
    }
}
