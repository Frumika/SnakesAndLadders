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
}


namespace AppStats
{
    extern bool exit;
}
