#ifndef ATLAS_H
#define ATLAS_H

#include <vector>
#include <SFML/Graphics/Texture.hpp>

class Atlas {
public:
    Atlas()=default;
    explicit Atlas(const char* path_template, size_t num);
    ~Atlas() = default;

public:
    const sf::Texture* operator[](size_t frame_index) const;

public:
    void loadFromFile(const char* path_template, size_t num);
    [[nodiscard]] const sf::Texture* getFrameImage(size_t frame_index)const;
    [[nodiscard]] size_t getFrameImageSize()const;
    void addFrameImage(const sf::Texture& texture);
    void clear();
private:
    std::vector<sf::Texture> img_list_;
};

#endif //ATLAS_H
