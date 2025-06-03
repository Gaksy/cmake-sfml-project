#include "../include/ResourcesUnit/Atlas.h"

Atlas::Atlas(const wchar_t* path_template, const size_t num) {
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

void Atlas::loadFromFile(const wchar_t* path_template, size_t num)
{
    img_list_.clear();
    img_list_.resize(num);

    constexpr size_t BUFFER_SIZE = 256;
    wchar_t filepath[BUFFER_SIZE];

    for (size_t i = 0; i < num; ++i) {
        swprintf(filepath, BUFFER_SIZE, path_template, i);
        if (!img_list_[i].loadFromFile(filepath)) {
            fprintf(stderr, "load file error: %ls\n", filepath);
        }
    }
}
