#include <Windows.h>
#include <time.h>
#include "0-Co-File-03-Namespaces.h"


int main(int argc, char* argv[])
{
    srand(unsigned int(time(0)));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    runApplication();

    Mix_Quit();
    Mix_CloseAudio();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();

    return 0;
}
