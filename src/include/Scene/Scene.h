#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Util/Camera.h"

class Scene {
public:
    explicit Scene(sf::Font font, sf::RenderWindow* p_window, const wchar_t* p_scene_label);
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

protected:
    static void resetSound(sf::Sound*& p_sound, const sf::SoundBuffer& sound_buffer, bool loop = false, bool play_now = false);
    static void freeSound(sf::Sound*& p_sound, bool async_wait_finished = false);
    void drawTexture(const sf::Vector2u& draw_pos, const sf::Texture& texture) const;

private:
    sf::Font base_font_;
    sf::RenderWindow* p_window_;
    const wchar_t* const p_scene_label_;
};

#endif //SCENE_H
