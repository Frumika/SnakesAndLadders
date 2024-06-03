#pragma once

#include "0-Co-File-01-Header.h"

namespace ScreenCharacter
{
    extern const int SCREEN_WIDTH;
    extern const int SCREEN_HEIGHT;
}


namespace SDLPointers
{
    extern SDL_Window* window;
    extern SDL_Renderer* renderer;
    extern TTF_Font* font;
    extern Mix_Music* music;
    extern Mix_Chunk* click;
}


namespace AppStats
{
    extern bool exit;
    extern int gameMode;
    extern double musicVolume;
    extern double soundVolume;
    extern int numOfPlayers;
    extern  SDL_Color textColor;
}
