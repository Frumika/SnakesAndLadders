#include "0-Co-File-01-Header.h"


/*
 * Функция принимает:
 * 1. Название файла (картинки), который должен стать текстурой.
 *
 * Функция возвращает:
 * 1. Указатель на созданную текстуру
 */
SDL_Texture* createTexture(const char* file)
{
    SDL_Surface* image = IMG_Load(file);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(SDLPointers::renderer, image);

    SDL_FreeSurface(image);
    
    return texture;
}
