#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/System/Vector2.hpp>

#include "Timer.h"


class Camera {
public:
    Camera();
    ~Camera()=default;
public:
    [[nodiscard]] const sf::Vector2f& getPosition()const;
    void setPosition(const sf::Vector2f& position);
    void resetPosition();

    void onUpdate(size_t delta);
    void shake(float strength, size_t duration);
private:
    sf::Vector2f position_;     // 摄像机位置
    Timer timer_shake_;         // 摄像机抖动定时器
    bool is_shaking_;           // 摄像机是否正在抖动
    float shaking_strength_;    // 摄像机抖动幅度
};


#endif //CAMERA_H
