#ifndef ANIMATION_H
#define ANIMATION_H

#include <mach/processor.h>

#include "ResourcesUnit/Atlas.h"
#include "Util/Camera.h"

namespace sf {
    class RenderWindow;
}

class Animation {
public:
    explicit Animation(sf::RenderWindow* p_window);
    ~Animation() = default;

public:
    void reset();
    void setAtlas(Atlas* atlas);
    void setLoop(bool loop);
    void setInterval(size_t ms);
    void setCallBack(std::function<void()> callback);
    [[nodiscard]] size_t getIndexFrame() const;
    [[nodiscard]] const sf::Texture* getCurrentFrame() const;
    [[nodiscard]] bool checkFinished() const;

    void onUpdate(size_t delta);
    void onDraw(const Camera& camera, float x, float y)const;
    void onDraw(float x, float y)const;

private:
    size_t timer_;
    size_t interval_;
    size_t index_frame_;
    bool is_loop_;
    Atlas* p_atlas_;
    std::function<void()> callback_;

    sf::RenderWindow* p_window_;
};

#endif //ANIMATION_H
