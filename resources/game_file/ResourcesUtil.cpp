#include "Resources/ResourcesUtil.h"

void flipImage(IMAGE* src_image, IMAGE* dst_image) {
    const int width = src_image->getwidth();
    const int height = src_image->getheight();
    Resize(dst_image, width, height);
    DWORD* src_buffer = GetImageBuffer(src_image);
    DWORD* dst_buffer = GetImageBuffer(dst_image);
    for(int y = 0; y < height; ++y) {
        for(int x = 0; x < width; ++x) {
            const int index_src = y * width + x;
            const int index_dst = y * width + (width - x - 1);
            dst_buffer[index_dst] = src_buffer[index_src];
        }
    }
}

void flipAtlas(const Atlas &src_atlas, Atlas &dst_atlas) {
    dst_atlas.clear();
    for(size_t index = 0; index < src_atlas.getFrameImageSize(); ++index) {
        IMAGE image_flipped;
        flipImage(src_atlas.getFrameImage(index), &image_flipped);
        dst_atlas.addFrameImage(image_flipped);
    }
}