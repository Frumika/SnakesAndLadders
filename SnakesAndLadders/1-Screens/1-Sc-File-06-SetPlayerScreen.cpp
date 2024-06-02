#include "1-Sc-File-01-Header.h"


void runSetPlayerScreen()
{
    SDL_Texture* playerBackground = createTexture("PlayerModeBackground.jpg");
    SDL_Rect rect = {0, 0, ScreenCharacter::SCREEN_WIDTH, ScreenCharacter::SCREEN_HEIGHT};
    SDL_Event event;

    SDL_RenderCopy(SDLPointers::renderer, playerBackground,NULL, &rect);

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
            if (event.button.x >= 211 && event.button.x <= 468 && event.button.y >= 170 && event.button.y <= 218)
            {
                playChunk(SDLPointers::click);
                AppStats::numOfPlayers = 2;
                quit = true;
            }

            if (event.button.x >= 211 && event.button.x <= 468 && event.button.y >= 247 && event.button.y <= 295)
            {
                playChunk(SDLPointers::click);
                AppStats::numOfPlayers = 3;
                quit = true;
            }

            if (event.button.x >= 211 && event.button.x <= 468 && event.button.y >= 324 && event.button.y <= 372)
            {
                playChunk(SDLPointers::click);
                AppStats::numOfPlayers = 4;
                quit = true;
            }

            if (event.button.x >= 211 && event.button.x <= 468 && event.button.y >= 405 && event.button.y <= 453)
            {
                playChunk(SDLPointers::click);
                quit = true;
            }
        }
    }
    while (quit == false);

    SDL_DestroyTexture(playerBackground);

    if (AppStats::numOfPlayers != 0) runGameScreen();
}
