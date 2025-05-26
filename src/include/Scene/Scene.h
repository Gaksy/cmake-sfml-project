#ifndef SCENE_H
#define SCENE_H

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Scene {
public:
    explicit Scene(sf::Font font, sf::RenderWindow* p_window, const wchar_t* p_scene_label);
    virtual ~Scene() = default;

public:
    virtual void onEnter()=0;
    virtual void onExit()=0;

    virtual void update()=0;
    virtual void onDraw()=0;
    virtual void onInput(const sf::Event& event)=0;

    virtual const sf::Font& getBaseFont()const;
    virtual void setBaseFont(const sf::Font& font);

    sf::RenderWindow& getWindow()const;
    void drawSceneLabel() const;
    const wchar_t* getSceneLabel() const;

private:
    sf::Font base_font_;
    sf::RenderWindow* p_window_;
    const wchar_t* const p_scene_label_;
};

#endif //SCENE_H
