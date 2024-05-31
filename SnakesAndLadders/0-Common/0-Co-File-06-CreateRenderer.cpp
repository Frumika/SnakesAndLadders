#include "0-Co-File-01-Header.h"


/*
 * Создает рендер и возвращает указатель на него
 */
SDL_Renderer* createRenderer()
{
    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(SDLPointers::window, -1, 0);
    return renderer;
}
