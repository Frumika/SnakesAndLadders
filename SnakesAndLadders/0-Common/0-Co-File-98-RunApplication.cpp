#include "0-Co-File-01-Header.h"


void runApplication()
{
    readSettingList();

    SDLPointers::window = createWindow();
    SDLPointers::renderer = createRenderer();
    SDLPointers::font = TTF_OpenFont("calibri.ttf", 20);

    loadMusic("FonMusic.mp3");
    loadChunk(SDLPointers::click, "ClikChunk.mp3");

    runMainScreen();

    editSettingList();

    SDL_DestroyWindow(SDLPointers::window);
    SDL_DestroyRenderer(SDLPointers::renderer);
    Mix_FreeMusic(SDLPointers::music);
    Mix_FreeChunk(SDLPointers::click);
    TTF_CloseFont(SDLPointers::font);
}
