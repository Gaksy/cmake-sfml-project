#include "include/Scene/Scene.h"

#include <utility>
#include <SFML/Graphics/Text.hpp>

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
