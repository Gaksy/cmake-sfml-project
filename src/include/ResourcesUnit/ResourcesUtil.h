#ifndef RESOURCESUTIL_H
#define RESOURCESUTIL_H

#include <SFML/Graphics/Texture.hpp>

#include "ResourcesUnit/Atlas.h"
#include "SFML/Audio/SoundBuffer.hpp"

void flipTextureHorizontally(const sf::Texture* original, sf::Texture* destination);
void flipAtlasHorizontally(const Atlas& original, Atlas& destination);
void loadTextureFromFile(sf::Texture* texture, const char* path_file);
void loadSoundFromFile(sf::SoundBuffer* soundBuffer, const char* path_file);

#endif //RESOURCESUTIL_H
