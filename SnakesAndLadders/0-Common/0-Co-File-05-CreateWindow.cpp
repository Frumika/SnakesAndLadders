#include "0-Co-File-01-Header.h"


/*
 * Создает окно и возвращает указатель на него
 */
SDL_Window* createWindow()
{
    SDL_Window* window = NULL;

    char title[] = {"Snake and ladders"};
    int x = SDL_WINDOWPOS_CENTERED;
    int y = SDL_WINDOWPOS_CENTERED;
    int w = ScreenCharacter::SCREEN_WIDTH;
    int h = ScreenCharacter::SCREEN_HEIGHT;
    Uint32 flags = SDL_WINDOW_SHOWN;

    window = SDL_CreateWindow(title, x, y, w, h, flags);

    return window;
}
