#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Util/Camera.h"

class Scene {
public:
    explicit Scene(sf::Font font, const wchar_t* p_scene_label);
    explicit Scene(const wchar_t* p_scene_label);
    virtual ~Scene() = default;

public:
    virtual void onEnter()=0;
    virtual void onExit()=0;

    virtual void onUpdate(size_t delta)=0;
    virtual void onDraw(const Camera& camera)=0;
    virtual void onInput(const sf::Event& event)=0;

    virtual const sf::Font& getBaseFont()const;
    virtual void setBaseFont(const sf::Font& font);

    sf::RenderWindow& getWindow()const;
    void drawSceneLabel() const;
    const wchar_t* getSceneLabel() const;

    sf::Vector2u getWindowSize()const;
    unsigned int getWindowWidth()const;
    unsigned int getWindowHeight()const;

    static sf::Font& getDefaultFont();

protected:
    static void resetSound(sf::Sound*& p_sound, const sf::SoundBuffer& sound_buffer, bool loop = false, bool play_now = false);
    static void freeSound(sf::Sound*& p_sound, bool async_wait_finished = false);
    void drawTexture(const sf::Vector2f& draw_pos, const sf::Texture& texture) const;
    void drawTexture(const Camera& camera, sf::Vector2f draw_pos, const sf::Texture& texture) const;
    void drawTexture(const sf::Vector2f& pos, float width, float height, const sf::Texture& texture, bool width_flipped = false) const;
    void drawTextWithShaded(const sf::Vector2f& pos, const sf::Text& text) const;
    void drawText(const sf::Vector2f& pos, const char* str, size_t size = 16, const sf::Color& color = sf::Color::Red) const;
    void drawText(const sf::Vector2f& pos, const wchar_t* str, size_t size = 16, const sf::Color& color = sf::Color::Red) const;

private:
    sf::Font base_font_;
    sf::RenderWindow* p_window_;
    const wchar_t* const p_scene_label_;
};

#endif //SCENE_H
