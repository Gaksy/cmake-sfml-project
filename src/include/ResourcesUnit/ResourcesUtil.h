#ifndef RESOURCESUTIL_H
#define RESOURCESUTIL_H

#include <SFML/Graphics/Texture.hpp>

#include "ResourcesUnit/Atlas.h"


void flipImage(sf::Texture* src_image, sf::Texture* dst_image);
void flipAtlas(const Atlas& src_atlas, Atlas& dst_atlas);


#endif //RESOURCESUTIL_H
