#include "../include/ResourcesUnit/Atlas.h"

Atlas::Atlas(const char* path_template, const size_t num) {
    loadFromFile(path_template, num);
}

const sf::Texture* Atlas::getFrameImage(const size_t frame_index) const {
    if (frame_index >= img_list_.size()) {
        return nullptr;
    }
    return &img_list_[frame_index];
}

size_t Atlas::getFrameImageSize() const {
    return img_list_.size();
}

void Atlas::addFrameImage(const sf::Texture& texture) {
    img_list_.push_back(texture);
}

void Atlas::clear(){
    img_list_.clear();
}

const sf::Texture* Atlas::operator[](const size_t frame_index) const{
    return getFrameImage(frame_index);
}

void Atlas::loadFromFile(const char* path_template, size_t num)
{
    img_list_.clear();
    img_list_.resize(num);

    constexpr size_t BUFFER_SIZE = 256;
    char filepath[BUFFER_SIZE];
    for (char& ch: filepath) {
        ch = '\0';
    }
    for (size_t i = 1; i <= num; ++i) {
        snprintf(filepath, BUFFER_SIZE, path_template, i);
        if (!img_list_[i - 1].loadFromFile(filepath)) {
            fprintf(stderr, "load file error: %s\n", filepath);
        }
    }
}
