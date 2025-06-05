#include "../include/Util/Timer.h"

#include <utility>

Timer::Timer():
    pass_time_(0),
    wait_time_(0),
    paused_(false),
    shotted_(false),
    one_shot_(false)
{
}

void Timer::onUpdate(const size_t delta)
{
    if (paused_) { return; }
    pass_time_ += delta;
    if (pass_time_ >= wait_time_)
    {
        // 如果不是单次触发或者是单词触发且没有触发过，并且回调函数可用
        if ((!one_shot_) | (one_shot_ && !shotted_) && callback_)
            callback_();

        shotted_ = true;
        pass_time_ = 0;
    }
}

void Timer::setCallback(std::function<void()> callback)
{
    callback_ = std::move(callback);
}

void Timer::restart()
{
    shotted_ = false;
    pass_time_ = 0;
}

void Timer::setWaitTime(const size_t val)
{
    wait_time_ = val;
}

void Timer::setOneShot(const bool flag)
{
    one_shot_ = flag;
}

void Timer::pause()
{
    paused_ = true;
}

void Timer::resume()
{
    paused_ = false;
}
