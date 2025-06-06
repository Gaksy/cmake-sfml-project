#ifndef PLATFROM_H
#define PLATFROM_H
#include "Camera.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Texture.hpp"

class Platform {
public:
    struct CollisionShape {
        float y;
        float left, right;
    };

public:
    Platform();
    Platform(const sf::Texture* p_texture, const CollisionShape& shape, const sf::Vector2f& position = {0, 0});
    ~Platform() = default;

public:
    void onDraw(const Camera& camera)const;

    void setShape(const CollisionShape& shape);
    [[nodiscard]] CollisionShape getShape()const;

    void setTexture(const sf::Texture* p_texture);
    [[nodiscard]] const sf::Texture* getTexture()const;

    void setRenderPosition(const sf::Vector2f& position);
    [[nodiscard]] const sf::Vector2f& getRenderPosition()const;

private:
    CollisionShape shape_;
    const sf::Texture* platform_texture_;
    sf::Vector2f render_position_;
};

#endif //PLATFROM_H
