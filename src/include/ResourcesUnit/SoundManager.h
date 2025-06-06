#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <string>
#include <map>
#include <SFML/Audio.hpp>

class SoundManager {
public:
    SoundManager();
    ~SoundManager();

protected:
    struct SoundPack {
        sf::SoundBuffer* p_buffer;
        sf::Sound* p_sound;
        bool loop;
    };

public:
    bool loadSound(const char* path, const char * key);
    void playSound(const char* key);
    void stopSound(const char* key);
    void pauseSound(const char* key);
    void setSoundLoop(const char* key, bool loop);
    void removeSound(const char* key);

private:
    using ResultType = std::pair<std::map<std::string, SoundPack>::iterator, bool>;
    using InsertType = std::pair<std::string, SoundPack>;
    using IteratorType = std::map<std::string, SoundPack>::iterator;

private:
    SoundPack* getSoundPack(const char* key);

private:
    std::map<std::string, SoundPack> sounds_;
};

#endif //SOUNDMANAGER_H
