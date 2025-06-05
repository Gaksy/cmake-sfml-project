#include "Scene/Scene.h"

#include <future>
#include <utility>
#include <SFML/Graphics/Text.hpp>

#include "SFML/System/Sleep.hpp"

Scene::Scene(sf::Font font, sf::RenderWindow* p_window, const wchar_t* const p_scene_label):
    base_font_(std::move(font)),
    p_window_(p_window),
    p_scene_label_(p_scene_label)
{ }

const sf::Font& Scene::getBaseFont()const
{
    return base_font_;
}

void Scene::setBaseFont(const sf::Font& font)
{
    base_font_ = font;
}

sf::RenderWindow& Scene::getWindow() const
{
    return *p_window_;
}

void Scene::drawSceneLabel() const
{
    sf::Text scene_label(getBaseFont(), getSceneLabel());
    scene_label.setCharacterSize(16);
    // scene_label.setStyle(sf::Text::Bold | sf::Text::Underlined);
    scene_label.setPosition({0, 0});
    scene_label.setFillColor(sf::Color::Black);

    getWindow().draw(scene_label);
}

const wchar_t* Scene::getSceneLabel() const
{
    return p_scene_label_;
}

void Scene::resetSound(sf::Sound*& p_sound, const sf::SoundBuffer& sound_buffer, const bool loop, const bool play_now)
{
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

void Scene::freeSound(sf::Sound*& p_sound, const bool async_wait_finished)
{
    if (!p_sound) return;

    if (async_wait_finished)
    {
        std::thread([&p_sound]() {
            while (p_sound && p_sound->getStatus() == sf::Sound::Status::Playing) {
                sf::sleep(sf::milliseconds(10));
            }
            delete p_sound;
            p_sound = nullptr;
        }).detach();  // 分离线程，不阻塞主线程
    }
    else
    {
        p_sound->stop();
        delete p_sound;
        p_sound = nullptr;
    }
}
