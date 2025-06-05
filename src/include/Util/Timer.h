#ifndef TIMER_H
#define TIMER_H

#include <functional>

class Timer {
public:
    Timer();
    ~Timer() = default;

    void onUpdate(size_t delta);
    void setCallback(std::function<void()> callback);

    void restart();
    void setWaitTime(size_t val);
    void setOneShot(bool flag);
    void pause();
    void resume();

private:
    size_t pass_time_;     // 已过时间
    size_t wait_time_;     // 等待时间
    bool paused_;       // 是否暂停
    bool shotted_;      // 是否触发
    bool one_shot_;     // 单次触发
    std::function<void()> callback_;
};

#endif //TIMER_H
