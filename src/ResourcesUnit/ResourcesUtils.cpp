#include <SFML/Graphics/Image.hpp>
#include "ResourcesUnit/ResourcesUtil.h"

void flipTextureHorizontally(const sf::Texture* original, sf::Texture* destination){
    // 获取原始纹理的图像
    sf::Image img = original->copyToImage();

    // 翻转图像
    img.flipHorizontally();

    // 创建新纹理
    destination->loadFromImage(img);
}

void flipAtlasHorizontally(const Atlas& original, Atlas& destination){
    for (size_t frame_index = 0; frame_index < original.getFrameImageSize(); ++frame_index) {
        sf::Texture flipped_texture;
        flipTextureHorizontally(original.getFrameImage(frame_index), &flipped_texture);
        destination.addFrameImage(flipped_texture);
    }
}

void loadTextureFromFile(sf::Texture* texture, const char* path_file) {
    if (!texture->loadFromFile(path_file)) {
        fprintf(stderr, "load file error: %s\n", path_file);
    }
}

void loadSoundFromFile(sf::SoundBuffer* soundBuffer, const char* path_file) {
    if (!soundBuffer->loadFromFile(path_file)) {
        fprintf(stderr, "load file error: %s\n", path_file);
    }
}