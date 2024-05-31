#include "1-Sc-File-01-Header.h"


void runRulesScreen()
{
    SDL_Texture* rulesBackground = createTexture("RulesBackground.jpg");
    SDL_Rect rect = {0, 0, ScreenCharacter::SCREEN_WIDTH, ScreenCharacter::SCREEN_HEIGHT};
    SDL_Event event;

    SDL_RenderCopy(SDLPointers::renderer, rulesBackground,NULL, &rect);

    SDL_RenderPresent(SDLPointers::renderer);

    bool quit = false;
    do
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
        {
            if (event.button.x >= 213 && event.button.x <= 469 && event.button.y >= 459 && event.button.y <= 506)
            {
                quit = true;
            }
        }
    }
    while (quit == false);

    SDL_DestroyTexture(rulesBackground);
}
