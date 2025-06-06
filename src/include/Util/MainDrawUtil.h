
#ifndef MAINDRAWUTIL_H
#define MAINDRAWUTIL_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Util/Camera.h"

void drawTexture(const sf::Vector2f& draw_pos, const sf::Texture& texture);
void drawTexture(const Camera& camera, sf::Vector2f draw_pos, const sf::Texture& texture);
void drawTexture(const sf::Vector2f& pos, float width, float height, const sf::Texture& texture, bool width_flipped = false);
void drawTextWithShaded(const sf::Vector2f& pos, const sf::Text& text);
void drawLine(const Camera& camera, sf::Vector2f pos_1, sf::Vector2f pos_2, sf::Color color = sf::Color::Red);
void drawText(const sf::Vector2f& pos, const char* str, size_t size = 16, const sf::Color& color = sf::Color::Red);
#endif //MAINDRAWUTIL_H
