#ifndef SECECTORSCENE_H
#define SECECTORSCENE_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Scene/Scene.h"

class SelectorScene: public Scene {
public:
    SelectorScene(const sf::Font& font, sf::RenderWindow* p_window);
    ~SelectorScene() override=default;

public:
    void onEnter()override;
    void onExit()override;
    void onUpdate(size_t delta)override;
    void onDraw(const Camera& camera)override;
    void onInput(const sf::Event& event)override;
};

#endif //SECECTORSCENE_H
