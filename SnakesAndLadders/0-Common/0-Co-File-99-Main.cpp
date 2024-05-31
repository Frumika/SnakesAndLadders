#include <Windows.h>
#include "0-Co-File-03-Namespaces.h"


int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    runApplication();

    SDL_DestroyWindow(SDLPointers::window);
    SDL_DestroyRenderer(SDLPointers::renderer);
    SDL_Quit();

    return 0;
}
