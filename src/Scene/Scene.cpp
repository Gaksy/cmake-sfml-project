#include "Scene/Scene.h"

#include <future>
#include <iostream>
#include <utility>
#include <SFML/System/Sleep.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "SFML/Graphics/Sprite.hpp"

extern sf::Font default_font;

Scene::Scene(sf::Font font, sf::RenderWindow* p_window, const wchar_t* const p_scene_label):
    base_font_(std::move(font)),
    p_window_(p_window),
    p_scene_label_(p_scene_label)
{ ; }

Scene::Scene(sf::RenderWindow* p_window, const wchar_t* p_scene_label):
    base_font_(getDefaultFont()),
    p_window_(p_window),
    p_scene_label_(p_scene_label)
{ ; }

const sf::Font& Scene::getBaseFont()const {
    return base_font_;
}

void Scene::setBaseFont(const sf::Font& font) {
    base_font_ = font;
}

sf::RenderWindow& Scene::getWindow() const {
    return *p_window_;
}

void Scene::drawSceneLabel() const {
    sf::Text scene_label(getBaseFont(), getSceneLabel());
    scene_label.setCharacterSize(16);
    // scene_label.setStyle(sf::Text::Bold | sf::Text::Underlined);
    scene_label.setPosition({0, 0});
    scene_label.setFillColor(sf::Color::Black);

    getWindow().draw(scene_label);
}

const wchar_t* Scene::getSceneLabel() const {
    return p_scene_label_;
}

sf::Vector2u Scene::getWindowSize() const {
    return p_window_->getSize();
}

unsigned int Scene::getWindowWidth() const {
    return p_window_->getSize().x;
}

unsigned int Scene::getWindowHeight() const {
    return p_window_->getSize().y;
}

sf::Font& Scene::getDefaultFont() {
    return default_font;
}

void Scene::resetSound(sf::Sound*& p_sound, const sf::SoundBuffer& sound_buffer, const bool loop, const bool play_now) {
    if (p_sound) {
        delete p_sound;
        p_sound = nullptr;
    }
    p_sound = new sf::Sound(sound_buffer);
    p_sound->setLooping(loop);
    if (play_now) {
        p_sound->play();
    }
}

void Scene::freeSound(sf::Sound*& p_sound, const bool async_wait_finished) {
    if (!p_sound) return;

    if (async_wait_finished) {
        std::thread([&p_sound]() {
            while (p_sound && p_sound->getStatus() == sf::Sound::Status::Playing) {
                sf::sleep(sf::milliseconds(10));
            }
            delete p_sound;
            p_sound = nullptr;
        }).detach();  // 分离线程，不阻塞主线程
    }
    else {
        p_sound->stop();
        delete p_sound;
        p_sound = nullptr;
    }
}

void Scene::drawTexture(const sf::Vector2f& draw_pos, const sf::Texture& texture) const {
    sf::RectangleShape shape;
    shape.setPosition(sf::Vector2f(draw_pos));
    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(texture.getSize()));

    getWindow().draw(shape);
}

void Scene::drawTexture(const Camera& camera, const sf::Vector2f draw_pos, const sf::Texture& texture) const {
    sf::Vector2f position = {0, 0};
    position.x = draw_pos.x - camera.getPosition().x;
    position.y = draw_pos.y - camera.getPosition().y;

    drawTexture(position, texture);
}

void Scene::drawTextWithShaded(const sf::Vector2f& pos, const sf::Text& text) const
{
    // Get the window reference
    sf::RenderWindow& window = getWindow();

    // Create a copy of the original text to use as the shadow
    sf::Text shadowText = text;

    // Set shadow properties
    shadowText.setPosition({pos.x + 2, pos.y + 2});  // Offset for shadow
    shadowText.setFillColor(sf::Color(0, 0, 0, 128));  // Semi-transparent black

    // Draw the shadow first
    window.draw(shadowText);

    // Draw the original text on top
    sf::Text mainText = text;
    mainText.setPosition(pos);
    window.draw(mainText);
}

void Scene::drawTexture(const sf::Vector2f& pos, const float width, const float height, const sf::Texture& texture,  const bool width_flipped) const {
    sf::RenderWindow& window = getWindow();
    sf::Sprite sprite(texture);
    sprite.setPosition(pos);

    // Check if texture is valid
    if (texture.getSize().x == 0 || texture.getSize().y == 0) {
        return;
    }

    // Calculate crop dimensions (clamp to texture size)
    int cropWidth = std::min(static_cast<int>(width), static_cast<int>(texture.getSize().x));
    int cropHeight = std::min(static_cast<int>(height), static_cast<int>(texture.getSize().y));

    // Ensure crop dimensions are valid
    if (cropWidth <= 0 || cropHeight <= 0) {
        return;
    }

    sf::IntRect cropRect;
    if (width_flipped) {
        // Start from the right edge of the texture
        int left = texture.getSize().x - cropWidth;
        cropRect = sf::IntRect({left, 0}, {cropWidth, cropHeight});
    } else {
        // Start from the left edge (default behavior)
        cropRect = sf::IntRect({0, 0}, {cropWidth, cropHeight});
    }
    sprite.setTextureRect(cropRect);

    // Draw
    window.draw(sprite);
}
