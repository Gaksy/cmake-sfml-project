#include "SoundManager.h"

#include "ResourcesUtil.h"

SoundManager::SoundManager() {
}

SoundManager::~SoundManager() {
    for (std::pair<std::string, SoundPack> p_sound_pack: sounds_) {
        if (p_sound_pack.second.p_buffer != nullptr) {
            delete p_sound_pack.second.p_buffer;
            p_sound_pack.second.p_buffer = nullptr;
        }
        if (p_sound_pack.second.p_sound != nullptr)
        {
            delete p_sound_pack.second.p_sound;
            p_sound_pack.second.p_sound = nullptr;
        }
    }
}

bool SoundManager::loadSound(const char* path, const char* key) {
    sf::SoundBuffer* p_buffer = new sf::SoundBuffer();
    if (!p_buffer->loadFromFile(path)) {
        delete p_buffer;
        return false;
    }

    ResultType result = sounds_.insert(InsertType(key, {p_buffer, nullptr, false}));

    return result.second;
}

void SoundManager::playSound(const char* key) {
    SoundPack* p_sound_pack = getSoundPack(key);
    if (!p_sound_pack) {return;}

    if (p_sound_pack->p_sound == nullptr) {
        p_sound_pack->p_sound = new sf::Sound(*p_sound_pack->p_buffer);
        p_sound_pack->p_sound->setLooping(p_sound_pack->loop);
    }

    p_sound_pack->p_sound->play();
}

void SoundManager::stopSound(const char* key)
{
    SoundPack* p_sound_pack = getSoundPack(key);
    if (!p_sound_pack) {return;}
    if (p_sound_pack->p_sound != nullptr) {
        p_sound_pack->p_sound->stop();
        delete p_sound_pack->p_sound;
        p_sound_pack->p_sound = nullptr;
    }
}

void SoundManager::pauseSound(const char* key)
{
    SoundPack* p_sound_pack = getSoundPack(key);
    if (!p_sound_pack) {return;}
    if (p_sound_pack->p_sound != nullptr) {
        p_sound_pack->p_sound->pause();
    }
}

void SoundManager::setSoundLoop(const char* key, const bool loop)
{
    SoundPack* p_sound_pack = getSoundPack(key);
    if (!p_sound_pack) {return;}
    p_sound_pack->loop = loop;
}

void SoundManager::removeSound(const char* key)
{
    const IteratorType it = sounds_.find(key);
    if (it != sounds_.end()) {
        if (it->second.p_buffer != nullptr) {
            delete it->second.p_buffer;
        }
        if (it->second.p_sound != nullptr) {
            delete it->second.p_sound;
        }
    }
    sounds_.erase(it);
}

SoundManager::SoundPack* SoundManager::getSoundPack(const char* key)
{
    const IteratorType result_it = sounds_.find(key);
    if (result_it != sounds_.end()) {
        return &result_it->second;
    }
    return nullptr;
}