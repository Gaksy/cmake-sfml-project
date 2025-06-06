#include "Util/MainDrawUtil.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

extern sf::RenderWindow window;
extern sf::Font default_font;

void drawTexture(const sf::Vector2f& draw_pos, const sf::Texture& texture) {
    sf::RectangleShape shape;
    shape.setPosition(sf::Vector2f(draw_pos));
    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(texture.getSize()));

    window.draw(shape);
}

void drawTexture(const Camera& camera, sf::Vector2f draw_pos, const sf::Texture& texture) {
    sf::Vector2f position = {0, 0};
    position.x = draw_pos.x - camera.getPosition().x;
    position.y = draw_pos.y - camera.getPosition().y;

    drawTexture(position, texture);
}

void drawTexture(const sf::Vector2f& pos, float width, float height, const sf::Texture& texture, bool width_flipped) {
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

void drawTextWithShaded(const sf::Vector2f& pos, const sf::Text& text)
{
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

void drawLine(const Camera& camera, sf::Vector2f pos_1, sf::Vector2f pos_2, sf::Color color)
{
    // Create a vertex array to represent the line (using sf::Lines primitive)
    sf::VertexArray line(sf::PrimitiveType::Lines, 2);

    // Set the positions of the line's endpoints
    line[0].position = pos_1;
    line[1].position = pos_2;

    // Set the color of the line (white by default, but you can change it)
    line[0].color = color;
    line[1].color = color;

    // Draw the line (assuming you have access to an sf::RenderTarget, like sf::RenderWindow)
    // You might need to adjust this depending on how your Camera class works
    window.draw(line);
}

void drawText(const sf::Vector2f& pos, const char* str, const size_t size, const sf::Color& color) {
    // Create a copy of the original text to use as the shadow
    sf::Text text(default_font, str);
    // Set shadow properties
    text.setCharacterSize(size);
    text.setPosition(pos);
    text.setFillColor(color);
    window.draw(text);
}