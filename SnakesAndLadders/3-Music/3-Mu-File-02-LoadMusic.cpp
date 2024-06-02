#include "3-Mu-File-01-Header.h"

void loadMusic(const char* file)
{
    
    if (SDLPointers::music != NULL) Mix_FreeMusic(SDLPointers::music);

    SDLPointers::music = Mix_LoadMUS(file);
    playMusic();
}
