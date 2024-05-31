#include "0-Co-File-01-Header.h"


void runApplication()
{
    SDLPointers::window = createWindow();
    SDLPointers::renderer = createRenderer();
    
    runMainScreen();

    SDL_DestroyWindow(SDLPointers::window);
    SDL_DestroyRenderer(SDLPointers::renderer);
    SDL_Quit();
}
