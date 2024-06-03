#include "1-Sc-File-01-Header.h"

void runEndScreen(int currentID)
{
    SDL_Texture* bonusBackground = createTexture("EndBackground.jpg");
    SDL_Rect rect = {0, 0, ScreenCharacter::SCREEN_WIDTH, ScreenCharacter::SCREEN_HEIGHT};
    SDL_Event event;

    SDL_RenderCopy(SDLPointers::renderer, bonusBackground,NULL, &rect);
    showNumOfCurrentPlayer(currentID, 744, 301);

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
            if (event.button.x >= 516 && event.button.x <= 773 && event.button.y >= 427 && event.button.y <= 475)
            {
                playChunk(SDLPointers::click);
                quit = true;
            }
        }
    }
    while (quit == false);

    SDL_DestroyTexture(bonusBackground);
}
