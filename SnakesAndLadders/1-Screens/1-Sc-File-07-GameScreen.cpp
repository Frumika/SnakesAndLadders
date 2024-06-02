#include "1-Sc-File-01-Header.h"
#include <iostream>

using namespace std;


void runGameScreen()
{
    SDL_Texture* gameBackground = createTexture("GameBackground_4.jpg");
    SDL_Rect rect = {0, 0, ScreenCharacter::SCREEN_WIDTH, ScreenCharacter::SCREEN_HEIGHT};
    SDL_Event event;

    SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);

    SDL_RenderPresent(SDLPointers::renderer);

    bool quit = false;
    do
    {
        SDL_PollEvent(&event);
        
        if (event.type == SDL_QUIT)
        {
            quit = true;
            AppStats::exit = true;
        }
        
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
        {
            if (event.button.x >= 873 && event.button.x <= 1130 && event.button.y >= 378 && event.button.y <= 426)
            {
                playChunk(SDLPointers::click);
                
            }

            if (event.button.x >= 873 && event.button.x <= 1130 && event.button.y >= 443 && event.button.y <= 491)
            {
                playChunk(SDLPointers::click);
                runSettingScreen();

                SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);

                SDL_RenderPresent(SDLPointers::renderer);
            }

            if (event.button.x >= 873 && event.button.x <= 1130 && event.button.y >= 509 && event.button.y <= 557)
            {
                playChunk(SDLPointers::click);
                runBonusScreen();

                SDL_RenderCopy(SDLPointers::renderer, gameBackground,NULL, &rect);

                SDL_RenderPresent(SDLPointers::renderer);
            }

            if (event.button.x >= 873 && event.button.x <= 1130 && event.button.y >= 575 && event.button.y <= 623)
            {
                playChunk(SDLPointers::click);
                quit = true;
            }
        }
    }
    while (quit == false);

    SDL_DestroyTexture(gameBackground);
}
