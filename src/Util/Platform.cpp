#include "Util/Platform.h"

#include "Util/MainDrawUtil.h"
#include "Scene/Scene.h"

extern bool is_debug;

Platform::Platform():
    shape_({0, 0, 0}),
    platform_texture_(nullptr),
    render_position_(0, 0)
{ ; }

Platform::Platform(const sf::Texture* p_texture, const CollisionShape& shape, const sf::Vector2f& position):
    shape_(shape),
    render_position_(position),
    platform_texture_(p_texture)
{ ; }

void Platform::onDraw(const Camera& camera) const {
    drawTexture(camera, render_position_, *platform_texture_);

    if (is_debug) {
        drawLine(camera, {shape_.left, shape_.y}, {shape_.right, shape_.y});
    }
}

void Platform::setShape(const CollisionShape& shape) {
    shape_ = shape;
}

Platform::CollisionShape Platform::getShape() const {
    return shape_;
}

void Platform::setTexture(const sf::Texture* p_texture) {
    platform_texture_ = p_texture;
}

const sf::Texture* Platform::getTexture() const {
    return platform_texture_;
}

void Platform::setRenderPosition(const sf::Vector2f& position) {
    render_position_ = position;
}

const sf::Vector2f& Platform::getRenderPosition() const {
    return render_position_;
}
